/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:12:55 by yabarhda          #+#    #+#             */
/*   Updated: 2026/01/05 17:58:41 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal()
{
	std::cout << "Animal default constructor called\n";
	type = "Animal";
}

Animal::~Animal()
{
	std::cout << "Animal destructor called\n";
}

Animal::Animal(const Animal& other)
{
	std::cout << "Animal copy constructor called\n";
	setType(other.getType());
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal copy assignement operator called\n";
	if (this == &other)
	{
		return *this;
	}
	setType(other.getType());
	return *this;
}

void Animal::setType(const std::string &type)
{
	this->type = type;
}

std::string Animal::getType(void) const
{
	return type;
}

void Animal::makeSound() const
{
	std::cout << "Animal makes Animal sounds\n";
}
