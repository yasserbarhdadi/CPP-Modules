/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:32:57 by yabarhda          #+#    #+#             */
/*   Updated: 2026/01/05 16:17:31 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	std::cout << "Constructor called\n";
	this->name = name;
	setHP(10);
	setEP(10);
	setAD(0);
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "Copy constructor called\n";
	name = other.name;
	setHP(other.getHP());
	setEP(other.getEP());
	setAD(other.getAD());
}

ClapTrap::~ClapTrap()
{
	std::cout << "Destructor called\n";
}

ClapTrap &ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "Copy assignement operator called\n";
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

void ClapTrap::attack(const std::string& target)
{
	if (getHP() > 0 && getEP() > 0)
	{
		setEP(getEP() - 1);
		std::cout << "ClapTrap " + name + " attacks " + target + ", causing " << getAD() << " points of damage!\n";
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << "ClapTrap " + name + " takes " << amount << " damage\n";
	if (getHP() < amount)
		setHP(0);
	else
		setHP(getHP() - amount);
}

void ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << "ClapTrap " + name + " repairs " << amount << ", new HP = " << getHP() << "\n";
	if (getEP() > 0 && getHP() != 0)
	{
		setHP(getHP() + amount);
		setEP(getEP() - 1);
	}
}

void ClapTrap::setHP(unsigned int value)
{
	HP = value;
}

void ClapTrap::setEP(unsigned int value)
{
	EP = value;
}

void ClapTrap::setAD(unsigned int value)
{
	AD = value;
}

unsigned int ClapTrap::getHP(void) const
{
	return HP;
}

unsigned int ClapTrap::getEP(void) const
{
	return EP;
}

unsigned int ClapTrap::getAD(void) const
{
	return AD;
}
		