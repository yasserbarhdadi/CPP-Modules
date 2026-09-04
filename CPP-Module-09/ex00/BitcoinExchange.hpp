#pragma once

#include <map>
#include <string>

class BitcoinExchange
{
private:
	std::map<std::string, float> _database;

	static bool isValidDate(const std::string& date);
	static bool parseValue(const std::string& text, float& value, std::string& error);
	void loadDatabase(const std::string& filename);

public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange& other);
	BitcoinExchange& operator=(const BitcoinExchange& other);
	~BitcoinExchange();

	void processFile(const std::string& filename);
};
