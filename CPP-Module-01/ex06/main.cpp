/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 10:24:58 by yabarhda          #+#    #+#             */
/*   Updated: 2025/09/16 10:30:54 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		{ std::cout << "Error\nToo few arguments." << std::endl; return 1; }

	Harl harl;
	harl.complain(av[1]);
	return 0;
}
