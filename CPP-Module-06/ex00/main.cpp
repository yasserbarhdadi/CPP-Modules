/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/27 11:03:48 by yabarhda          #+#    #+#             */
/*   Updated: 2026/07/27 11:20:33 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
	if (ac != 2) {
		std::cerr << "Usage: /convert <number>" << std::endl;
		return 1;
	}
	ScalarConverter::convert(av[1]);
	return 0;
}
