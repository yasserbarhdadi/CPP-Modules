/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:36:38 by yabarhda          #+#    #+#             */
/*   Updated: 2025/12/11 09:49:50 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

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
				phonebook.add_contact();
			else if (input == "SEARCH")
				phonebook.search_contact();
			else if (input == "EXIT")
				break;
		}	
	}
	catch(int) {}
	return (0);
}
