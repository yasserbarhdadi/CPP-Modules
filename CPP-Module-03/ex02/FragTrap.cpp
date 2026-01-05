/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:33:33 by yabarhda          #+#    #+#             */
/*   Updated: 2026/01/05 16:29:18 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	std::cout << "FragTrap Constructor called\n";
	this->name = name;
	setHP(100);
	setEP(100);
	setAD(30);
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap Copy constructor called\n";
	name = other.name;
	setHP(other.getHP());
	setEP(other.getEP());
	setAD(other.getAD());
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap Destructor called\n";
}

FragTrap &FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap Copy assignement operator called\n";
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

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << name << " is requesting a high five!\n";
}
