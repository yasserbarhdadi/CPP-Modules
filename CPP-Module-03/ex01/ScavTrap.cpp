/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:33:21 by yabarhda          #+#    #+#             */
/*   Updated: 2026/01/05 16:20:03 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	std::cout << "ScavTrap Constructor called\n";
	this->name = name;
	setHP(100);
	setEP(50);
	setAD(20);
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap Copy constructor called\n";
	name = other.name;
	setHP(other.getHP());
	setEP(other.getEP());
	setAD(other.getAD());
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap Destructor called\n";
}

ScavTrap &ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap Copy assignement operator called\n";
	if (this == &other)
	{
		return *this;
	}
	name = other.name;
	setHP(other.getHP());
	setEP(other.getEP());
	setAD(other.getAD());	
	return *this;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << name << " is now in Gate keeper mode\n";
}

void ScavTrap::attack(const std::string& target)
{
	if (getHP() > 0 && getEP() > 0)
	{
		setEP(getEP() - 1);
		std::cout << "ScavTrap " + name + " attacks " + target + ", causing " << getAD() << " points of damage!\n";
	}
}
