/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 10:36:51 by yabarhda          #+#    #+#             */
/*   Updated: 2025/08/26 11:05:54 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

void Zombie::announce()
{
	std::cout << get_name() + ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::set_name(std::string name)
{
	this->name = name;
}

std::string Zombie::get_name(void)
{
	return (name);
}

Zombie::~Zombie()
{
	std::cout << get_name() + ": Deleted" << std::endl;
}
