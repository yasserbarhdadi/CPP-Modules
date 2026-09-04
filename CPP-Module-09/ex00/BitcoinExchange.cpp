#include "BitcoinExchange.hpp"
#include <cerrno>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

BitcoinExchange::BitcoinExchange()
{
    loadDatabase("data.csv");
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) : _database(other._database) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    if (this != &other)
        _database = other._database;
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

static bool isDigits(const std::string& text)
{
    if (text.empty())
        return false;
    for (std::size_t index = 0; index < text.size(); ++index)
        if (text[index] < '0' || text[index] > '9')
            return false;
    return true;
}

bool BitcoinExchange::isValidDate(const std::string& date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        return false;
    if (!isDigits(date.substr(0, 4)) || !isDigits(date.substr(5, 2)) || !isDigits(date.substr(8, 2)))
        return false;
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    if (month < 1 || month > 12)
        return false;
    int year = std::atoi(date.substr(0, 4).c_str());
    if (month == 2 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
        daysInMonth[1] = 29;
    return day >= 1 && day <= daysInMonth[month - 1];
}

bool BitcoinExchange::parseValue(const std::string& text, float& value, std::string& error)
{
    char *end = NULL;
    const char *start = text.c_str();
    while (*start == ' ' || *start == '\t')
        ++start;
    if (*start == '\0')
        return false;
    errno = 0;
    double parsed = std::strtod(start, &end);
    while (*end == ' ' || *end == '\t')
        ++end;
    if (errno == ERANGE || end == start || *end != '\0')
        return false;
    if (parsed < 0.0)
    {
        error = "Error: not a positive number.";
        return false;
    }
    if (parsed > 1000.0)
    {
        error = "Error: too large a number.";
        return false;
    }
    value = static_cast<float>(parsed);
    return true;
}

void BitcoinExchange::loadDatabase(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open file.");
	}
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::size_t comma = line.find(',');
        if (comma == std::string::npos)
            continue;
        std::string date = line.substr(0, comma);
        float price;
        std::string error;
        if (isValidDate(date) && parseValue(line.substr(comma + 1), price, error))
            _database[date] = price;
    }
    if (_database.empty())
        throw std::runtime_error("Error: could not open file.");
}

void BitcoinExchange::processFile(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
        throw std::runtime_error("Error: could not open file.");
    std::string line;
    std::getline(file, line);
    while (std::getline(file, line))
    {
        std::size_t separator = line.find('|');
        if (separator == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = line.substr(0, separator);
        while (!date.empty() && (date[date.size() - 1] == ' ' || date[date.size() - 1] == '\t'))
            date.erase(date.size() - 1);
        while (!date.empty() && (date[0] == ' ' || date[0] == '\t'))
            date.erase(0, 1);
        float amount;
        if (!isValidDate(date))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string error;
        if (!parseValue(line.substr(separator + 1), amount, error))
        {
            if (!error.empty())
                std::cerr << error << std::endl;
            else
                std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::map<std::string, float>::const_iterator rate = _database.lower_bound(date);
        if (rate == _database.begin() && (rate == _database.end() || rate->first > date))
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (rate == _database.end() || rate->first > date)
            --rate;
        std::cout << date << " => " << amount << " = " << amount * rate->second << std::endl;
    }
}