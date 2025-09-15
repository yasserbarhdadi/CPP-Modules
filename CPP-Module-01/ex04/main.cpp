/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/14 17:11:41 by yabarhda          #+#    #+#             */
/*   Updated: 2025/09/15 15:23:28 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

int main(int ac, char **av)
{
	if (ac != 4) {
		std::cerr << "Error\nToo few arguments." << std::endl;
		return 1;
	}
	std::string filename = av[1];

	std::fstream filein(filename);
	filename += ".replace";
	std::ofstream fileout(filename);	

	std::string buffer;
	std::string line;
	
	while (std::getline(filein, line))
		buffer += line, buffer += "\n";

	buffer.pop_back();
	std::string s1 = av[2];
	std::string s2 = av[3];

	std::string::size_type len = s1.length();
	std::string::size_type x = buffer.find(s1);
	while (x != std::string::npos)
	{
		buffer.erase(x, len);
		buffer.insert(x, s2);
		x = buffer.find(s1);
	}
	fileout << buffer;
	filein.close();
	fileout.close();
	return 0;
}
