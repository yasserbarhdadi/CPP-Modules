/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:36:38 by yabarhda          #+#    #+#             */
/*   Updated: 2025/08/21 17:36:40 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int search_contact(PhoneBook phonebook)
{
	int				index;
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
	std::cin >> index;

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
	else if (phonebook.arr[index].get_status() == true)
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
			std::string tmp;
			std::cout << "first name: ";
			std::cin >> tmp;
			phonebook.arr[i].set_first_name(tmp);
			std::cout << "last name: ";
			std::cin >> tmp;
			phonebook.arr[i].set_last_name(tmp);
			std::cout << "nickname: ";
			std::cin >> tmp;
			phonebook.arr[i].set_nickname(tmp);
			std::cout << "phone number: ";
			std::cin >> tmp;
			phonebook.arr[i].set_phone_number(tmp);
			std::cout << "darkest secret: ";
			std::cin >> tmp;
			phonebook.arr[i].set_dark_secret(tmp);
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
		std::cin.clear();
		std::cin >> input;
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
