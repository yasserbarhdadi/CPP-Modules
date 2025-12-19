/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 17:11:41 by yabarhda          #+#    #+#             */
/*   Updated: 2025/12/19 16:11:20 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

void replace(char **av)
{
	if (!av[2][0])
		return ;

	std::string filename = av[1];

	std::fstream filein(filename.c_str());

	if (!filein.is_open())
	{
		std::cout << "Failed to open the file\nPermission denied or file not found" << std::endl;
		return ;
	}

	if (filein.peek() == EOF)
	{
		std::cout << "Error\nEmpty file" << std::endl;
		filein.close();
		return ;
	}

	filename += ".replace";
	std::ofstream fileout(filename.c_str());

	std::string buffer;
	std::string line;
	
	while (std::getline(filein, line))
		buffer += line, buffer += "\n";

	buffer.erase(buffer.size() - 1, 1);

	std::string s1 = av[2];
	std::string s2 = av[3];

	std::string::size_type len = s1.length();
	std::string::size_type x = buffer.find(s1);

	while (x != std::string::npos)
	{
		buffer.erase(x, len);
		buffer.insert(x, s2);
		x = buffer.find(s1, x + s2.length());
	}

	fileout << buffer;

	filein.close();
	fileout.close();	
}

int main(int ac, char **av)
{
	if (ac != 4) {
		std::cout << "Usage: ./sed {filename} {string to find} {string to replace it with}" << std::endl;
		return 1;
	}
	replace(av);
	return 0;
}
