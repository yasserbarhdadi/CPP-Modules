/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:32:57 by yabarhda          #+#    #+#             */
/*   Updated: 2026/01/05 10:07:27 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
	this->name = name;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	name = other.name;
	setHP(other.getHP());
	setEP(other.getEP());
	setAD(other.getAD());
}

ClapTrap::~ClapTrap() {}

ClapTrap &ClapTrap::operator=(const ClapTrap& other)
{
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
	if (HP > 0 && EP > 0)
	{
		std::cout << "ClapTrap" + name + " attacks " + target + ", causing " << getAD() << " points of damage!\n";
		setEP(getEP() - 1);
	}
}

void ClapTrap::takeDamage(unsigned int amount)
{
	
}

void ClapTrap::beRepaired(unsigned int amount)
{
	setHP(getHP() + amount);
	setEP(getEP() - 1);
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
		