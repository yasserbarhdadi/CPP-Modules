/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 09:41:45 by yabarhda          #+#    #+#             */
/*   Updated: 2025/12/11 09:50:20 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void PhoneBook::print_columns(void)
{
	std::cout << std::right << std::setw(10) << "index";
	std::cout << "|";
	std::cout << std::right << std::setw(10) << "first name";
	std::cout << "|";
	std::cout << std::right << std::setw(10) << "last name";
	std::cout << "|";
	std::cout << std::right << std::setw(10) << "nickname" << std::endl;
}

std::string PhoneBook::get_contact_value(const std::string &prompt)
{
	std::string input;
	do {
		std::cout << prompt << ": ";
		std::getline(std::cin, input);
		if (std::cin.eof())
			throw(1);
	} while (input.empty());
	return (input);
}

void PhoneBook::add_contact()
{
	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		if (arr[i].get_status() == true)
		{
			arr[i].set_first_name(get_contact_value("first name"));
			arr[i].set_last_name(get_contact_value("last name"));
			arr[i].set_nickname(get_contact_value("nickname"));
			arr[i].set_phone_number(get_contact_value("phone number"));
			arr[i].set_dark_secret(get_contact_value("darkest secret"));
			arr[i].set_status(false);
			break;
		}
		else if (i + 1 == MAX_CONTACTS)
		{
			i = -1;
			for (int j = 0; j < MAX_CONTACTS; j++)
				arr[j].set_status(true);
		}
	}
}

void PhoneBook::search_contact()
{
	int				index;
	std::string		input;
	std::string		tmp;

	print_columns();
	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		if (!arr[i].get_first_name().empty())
		{
			std::cout << std::right << std::setw(10) << i;
			std::cout << "|";
			tmp = arr[i].get_first_name().substr(0, 9);
			if (arr[i].get_first_name().length() > 10)
				tmp += ".";
			std::cout << std::right << std::setw(10) << tmp;
			std::cout << "|";
			tmp = arr[i].get_last_name().substr(0, 9);
			if (arr[i].get_last_name().length() > 10)
				tmp += ".";
			std::cout << std::right << std::setw(10) << tmp;
			std::cout << "|";
			tmp = arr[i].get_nickname().substr(0, 9);
			if (arr[i].get_nickname().length() > 10)
				tmp += ".";
			std::cout << std::right << std::setw(10) << tmp << std::endl;
		}
	}

	std::cout << "Enter an index: ";
	std::getline(std::cin, input);
	if (std::cin.fail())
		throw(1);
	index = input[0] - '0';
	if (input[0] < '0' || input[0] > '8' || input[1]) 
		std::cout << "Invalid index" << std::endl;
	else if (index < 0 || index >= MAX_CONTACTS)
		std::cout << "Index out of range" << std::endl;
	else if (arr[index].get_status() == true && arr[index].get_first_name().empty())
		std::cout << "Empty contact" << std::endl;
	else
	{
		std::cout << "first name: " << arr[index].get_first_name() << std::endl;
		std::cout << "last name: " << arr[index].get_last_name() << std::endl;
		std::cout << "nickname: " << arr[index].get_nickname() << std::endl;
		std::cout << "phone number: " << arr[index].get_phone_number() << std::endl;
		std::cout << "darkest secret: " << arr[index].get_dark_secret() << std::endl;
	}
}
