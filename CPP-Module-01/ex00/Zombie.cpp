/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 11:45:43 by yabarhda          #+#    #+#             */
/*   Updated: 2025/12/18 12:05:02 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name)
{
	this->name = name;
}

Zombie::~Zombie()
{
	std::cout << name + " Object destroyed" << std::endl;
}

void Zombie::announce(void)
{
	std::cout << name + ": BraiiiiiiinnnzzzZ..." << std::endl;
}
