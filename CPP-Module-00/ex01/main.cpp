/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:36:38 by yabarhda          #+#    #+#             */
/*   Updated: 2025/08/31 16:39:03 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int search_contact(PhoneBook phonebook)
{
	int				index;
	std::string		input;
	std::string		tmp;

	std::cout << std::right << std::setw(10) << "index";
	std::cout << "|";
	std::cout << std::right << std::setw(10) << "first name";
	std::cout << "|";
	std::cout << std::right << std::setw(10) << "last name";
	std::cout << "|";
	std::cout << std::right << std::setw(10) << "nickname" << std::endl;

	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		if (!phonebook.arr[i].get_first_name().empty())
		{
			std::cout << std::right << std::setw(10) << i;
			std::cout << "|";
			tmp = phonebook.arr[i].get_first_name().substr(0, 9);
			if (phonebook.arr[i].get_first_name().length() > 10)
				tmp += ".";
			std::cout << std::right << std::setw(10) << tmp;
			std::cout << "|";
			tmp = phonebook.arr[i].get_last_name().substr(0, 9);
			if (phonebook.arr[i].get_last_name().length() > 10)
				tmp += ".";
			std::cout << std::right << std::setw(10) << tmp;
			std::cout << "|";
			tmp = phonebook.arr[i].get_nickname().substr(0, 9);
			if (phonebook.arr[i].get_nickname().length() > 10)
				tmp += ".";
			std::cout << std::right << std::setw(10) << tmp << std::endl;
		}
	}

	std::cout << "Enter an index: ";
	std::getline(std::cin, input);
	index = atoi(input.c_str());
	if (std::cin.fail())
	{
		std::cout << "Invalid input" << std::endl;
		std::cin.clear();
		std::cin.ignore(10000, '\n');
		return (1);
	}
	if (index < 0 || index >= MAX_CONTACTS)
	{
		std::cout << "Index out of range" << std::endl;
		return (1);
	}
	else if (phonebook.arr[index].get_status() == true && phonebook.arr[index].get_first_name().empty())
	{
		std::cout << "Empty contact" << std::endl;
		return (1);
	}
	else
	{
		std::cout << "first name: " << phonebook.arr[index].get_first_name() << std::endl;
		std::cout << "last name: " << phonebook.arr[index].get_last_name() << std::endl;
		std::cout << "nickname: " << phonebook.arr[index].get_nickname() << std::endl;
		std::cout << "phone number: " << phonebook.arr[index].get_phone_number() << std::endl;
		std::cout << "darkest secret: " << phonebook.arr[index].get_dark_secret() << std::endl;
	}
	return (1);
}

int	add_contact(PhoneBook& phonebook)
{
	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		if (phonebook.arr[i].get_status() == true)
		{
			std::string input;
			do {
				std::cout << "first name: ";
				std::getline(std::cin, input);
				if (std::cin.eof())
					return (0);
			} while ((int)input.front() == 0);
			phonebook.arr[i].set_first_name(input);
			do {
				std::cout << "last name: ";
				std::getline(std::cin, input);
				if (std::cin.eof())
					return (0);
			} while ((int)input.front() == 0);
			phonebook.arr[i].set_last_name(input);
			do {
				std::cout << "nickname: ";
				std::getline(std::cin, input);
				if (std::cin.eof())
					return (0);
			} while ((int)input.front() == 0);
			phonebook.arr[i].set_nickname(input);
			do {
				std::cout << "phone number: ";
				std::getline(std::cin, input);
				if (std::cin.eof())
					return (0);
			} while ((int)input.front() == 0);
			phonebook.arr[i].set_phone_number(input);
			do {
				std::cout << "darkest secret: ";
				std::getline(std::cin, input);
				if (std::cin.eof())
					return (0);
			} while ((int)input.front() == 0);
			phonebook.arr[i].set_dark_secret(input);
			phonebook.arr[i].set_status(false);
			break;
		}
		else if (i + 1 == MAX_CONTACTS)
		{
			i = -1;
			for (int j = 0; j < MAX_CONTACTS; j++)
				phonebook.arr[j].set_status(true);
		}
		std::cout << std::flush;
	}
	return (1);
}

int main()
{
	std::string input;
	PhoneBook phonebook;
	std::cout << "Usage: ADD, SEARCH and EXIT" << std::endl;
	while (!(std::cin.eof()))
	{
		std::cout << "> " << std::flush;
		std::getline(std::cin, input);
		if (!strcmp(input.c_str(), "ADD"))
		{
			if (!add_contact(phonebook))
				return (1);
		}
		else if (!strcmp(input.c_str(), "SEARCH"))
		{
			if (!search_contact(phonebook))
				return (1);
		}
		else if (!strcmp(input.c_str(), "EXIT"))
			break;
	}
	return (0);	
}
