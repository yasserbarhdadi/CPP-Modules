/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:38:05 by yabarhda          #+#    #+#             */
/*   Updated: 2025/12/18 16:51:10 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::Zombie() {}

Zombie::~Zombie()
{
	std::cout << name + " Object destroyed" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name + ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setname(std::string name)
{
	this->name = name;
}
