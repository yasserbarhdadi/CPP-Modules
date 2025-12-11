/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:36:38 by yabarhda          #+#    #+#             */
/*   Updated: 2025/12/11 09:21:14 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void print_columns(void)
{
	std::cout << std::right << std::setw(10) << "index";
	std::cout << "|";
	std::cout << std::right << std::setw(10) << "first name";
	std::cout << "|";
	std::cout << std::right << std::setw(10) << "last name";
	std::cout << "|";
	std::cout << std::right << std::setw(10) << "nickname" << std::endl;
}

void search_contact(PhoneBook phonebook)
{
	int				index;
	std::string		input;
	std::string		tmp;

	print_columns();
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
	if (std::cin.fail())
		throw(1);
	index = input[0] - '0';
	if (input[0] < '0' || input[0] > '8' || input[1]) 
		std::cout << "Invalid index" << std::endl;
	else if (index < 0 || index >= MAX_CONTACTS)
		std::cout << "Index out of range" << std::endl;
	else if (phonebook.arr[index].get_status() == true && phonebook.arr[index].get_first_name().empty())
		std::cout << "Empty contact" << std::endl;
	else
	{
		std::cout << "first name: " << phonebook.arr[index].get_first_name() << std::endl;
		std::cout << "last name: " << phonebook.arr[index].get_last_name() << std::endl;
		std::cout << "nickname: " << phonebook.arr[index].get_nickname() << std::endl;
		std::cout << "phone number: " << phonebook.arr[index].get_phone_number() << std::endl;
		std::cout << "darkest secret: " << phonebook.arr[index].get_dark_secret() << std::endl;
	}
}

std::string get_contact_value(const std::string &prompt)
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

void	add_contact(PhoneBook& phonebook)
{
	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		if (phonebook.arr[i].get_status() == true)
		{
			phonebook.arr[i].set_first_name(get_contact_value("first name"));
			phonebook.arr[i].set_last_name(get_contact_value("last name"));
			phonebook.arr[i].set_nickname(get_contact_value("nickname"));
			phonebook.arr[i].set_phone_number(get_contact_value("phone number"));
			phonebook.arr[i].set_dark_secret(get_contact_value("darkest secret"));
			phonebook.arr[i].set_status(false);
			break;
		}
		else if (i + 1 == MAX_CONTACTS)
		{
			i = -1;
			for (int j = 0; j < MAX_CONTACTS; j++)
				phonebook.arr[j].set_status(true);
		}
	}
}

int main()
{
	std::string input;
	PhoneBook phonebook;
	std::cout << "Usage: ADD, SEARCH and EXIT" << std::endl;
	try
	{
		while (!(std::cin.eof()))
		{
			std::cout << "> ";
			std::getline(std::cin, input);
			if (input == "ADD")
				add_contact(phonebook);
			else if (input == "SEARCH")
				search_contact(phonebook);
			else if (input == "EXIT")
				break;
		}	
	}
	catch(int) {}
	return (0);
}
