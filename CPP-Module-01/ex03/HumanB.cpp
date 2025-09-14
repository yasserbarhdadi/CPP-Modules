/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 11:25:20 by yabarhda          #+#    #+#             */
/*   Updated: 2025/09/14 17:05:44 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

void HumanB::attack()
{
	if (weapon == nullptr)
		std::cout << getName() + " attacks with nothing" << std::endl;
	else
		std::cout << getName() + " attacks with their " + weapon->getType() << std::endl;
}

void HumanB::setName(std::string name)
{
	this->name = name;
}

std::string HumanB::getName() const
{
	return (name);	
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}
