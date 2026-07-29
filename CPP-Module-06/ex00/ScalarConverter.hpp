/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 11:05:38 by yabarhda          #+#    #+#             */
/*   Updated: 2026/07/29 11:05:42 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <iomanip>
#include <stdlib.h>
#include <limits.h>

class ScalarConverter 
{
	public:
		static void convert(const std::string& str);
	private:
		ScalarConverter();
		~ScalarConverter();
		ScalarConverter(const ScalarConverter &);
		ScalarConverter &operator=(const ScalarConverter &);

		static bool isSpecial(const std::string &s);
		static bool isChar(const std::string &s);
		static bool isInt(const std::string &s);
		static bool isFloat(const std::string &s);
		static bool isDouble(const std::string &s);

		static void convertSpecial(const std::string &s);
		static void convertChar(const std::string &s);
		static void convertInt(const std::string &s);
		static void convertFloat(const std::string &s);
		static void convertDouble(const std::string &s);

		static void printImpossible();
};
