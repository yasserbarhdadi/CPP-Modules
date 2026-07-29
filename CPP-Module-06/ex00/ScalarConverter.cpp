/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 11:22:19 by yabarhda          #+#    #+#             */
/*   Updated: 2026/07/29 11:09:30 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &o) {(void)o;}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &o) {(void)o; return *this;}

bool ScalarConverter::isFloat(const std::string &s)
{
    if (s[s.length() - 1] == 'f') {
        size_t index = 0;
        int decimal_c = 0;

        for (size_t i = 0; i < s.size(); i++) {
            if (s[i] == '.')
                decimal_c++;
        }
        if (decimal_c != 1)
            return false;
        if (s[index] == '+' || s[index] == '-')
            index++;
        if (s.length() == index)
            return false;
            
        if (s.find_first_of("0123456789") == std::string::npos)
            return false;
            
        if (s.find_first_not_of("0123456789.", index) == s.length() - 1)
            return true;
    }
    return false;
}

bool ScalarConverter::isDouble(const std::string &s)
{
    size_t index = 0;
    int decimal_c = 0;

    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == '.')
            decimal_c++;
    }
    if (decimal_c != 1)
        return false;
    if (s[index] == '+' || s[index] == '-')
        index++;
    if (s.length() == index)
        return false;
        
    if (s.find_first_of("0123456789") == std::string::npos)
        return false;
        
    if (s.find_first_not_of("0123456789.", index) == std::string::npos)
        return true;
        
    return false;   
}

bool ScalarConverter::isInt(const std::string &s)
{
	size_t index = 0;
	if (s[index] == '+' || s[index] == '-')
		index++;
	if (s.length() == index)
		return false;
	if (s.find_first_not_of("0123456789", index) == std::string::npos)
		return true;
	return false;
}

bool ScalarConverter::isChar(const std::string &s)
{
	if (s.size() == 1 && isprint(s[0]) && !isdigit(s[0])) {
		return true;
	}
	return false;
}

bool ScalarConverter::isSpecial(const std::string &s)
{
	if (s == "nan" || s == "-inf" || s == "+inf" || s == "-inff" || s == "+inff" || s == "nanf") {
		return true;
	}
	return false;
}

void ScalarConverter::printImpossible()
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: impossible\n";
	std::cout << "double: impossible" << std::endl;	
}

void ScalarConverter::convertSpecial(const std::string &s)
{
	std::string double_s;
	std::string float_s;

	if (s == "nanf" || s == "-inff" || s == "+inff") {
		float_s = s;
		double_s = s.substr(0, s.size() - 1);
	}
	else {
		float_s = s + "f";
		double_s = s;		
	}

	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	std::cout << "float: " << float_s << "\n";
	std::cout << "double: " << double_s << std::endl;
}

void ScalarConverter::convertChar(const std::string &s)
{
	char c = s[0];
	int i = static_cast<int>(c);
	float f = static_cast<float>(c);
	double d = static_cast<double>(c);

	std::cout << "char: '" << c << "'\n";
	std::cout << "int: " << i << "\n";
	std::cout << "float: " << f << ".0f" << "\n";
	std::cout << "double: " << d << ".0" << std::endl;	
}

void ScalarConverter::convertInt(const std::string &s)
{
	long val = strtol(s.c_str(), NULL, 10);
	if (errno == ERANGE || val < INT_MIN || val > INT_MAX) {
		printImpossible();
		return ;
	}

	int i = static_cast<int>(val);
	char c = static_cast<char>(i);
	float f = static_cast<float>(i);
	double d = static_cast<double>(i);

	if (i < 0 || i > 127) {
		std::cout << "char: impossible\n";
	}
	else if (!isprint(i)) {
		std::cout << "char: Non displayable\n";
	}
	else {
		std::cout << "char: '" << c << "'\n";
	}

	std::cout << std::fixed << std::setprecision(1);
	std::cout << "int: " << i << "\n";
	std::cout << "float: " << f << "f" << "\n";
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convertDouble(const std::string &s)
{
	double d = strtod(s.c_str(), NULL);
	if (errno == ERANGE) {
		printImpossible();
		return ;
	}

	float f = static_cast<float>(d);
	if (d < INT_MIN || d > INT_MAX) {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
	}
	else {
		int i = static_cast<int>(d);
		char c = static_cast<char>(i);
		if (i < 0 || i > 127) {
			std::cout << "char: impossible\n";
		}
		else if (!isprint(i)) {
			std::cout << "char: Non displayable\n";
		}
		else {
			std::cout << "char: '" << c << "'\n";
		}
		std::cout << "int: " << i << "\n";
	}
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f\n";
	std::cout << "double: " << d << std::endl;
}

void ScalarConverter::convertFloat(const std::string &s)
{
	double val = strtod(s.substr(0, s.size() - 1).c_str(), NULL);
	if (errno == ERANGE) {
		printImpossible();
		return ;
	}
	float f = static_cast<float>(val);
	double d = static_cast<double>(f);
	if (d < INT_MIN || d > INT_MAX) {
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
	}
	else {
		int i = static_cast<int>(d);
		char c = static_cast<char>(i);
		if (i < 0 || i > 127) {
			std::cout << "char: impossible\n";
		}
		else if (!isprint(i)) {
			std::cout << "char: Non displayable\n";
		}
		else {
			std::cout << "char: '" << c << "'\n";
		}
		std::cout << "int: " << i << "\n";
	}
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: " << f << "f\n";
	std::cout << "double: " << d << std::endl;	
}

void ScalarConverter::convert(const std::string& s)
{
	if (isSpecial(s)) {
		convertSpecial(s);
		return ;
	}
	else if (isChar(s)) {
		convertChar(s);
		return ;
	}
	else if (isInt(s)) {
		convertInt(s);
		return ;		
	}
	else if (isDouble(s)) {
		convertDouble(s);
		return ;		
	}
	else if (isFloat(s)) {
		convertFloat(s);
		return ;		
	}
}
