/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:42:39 by yabarhda          #+#    #+#             */
/*   Updated: 2026/01/06 20:51:04 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "WrongAnimal default constructor called\n";
	type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal destructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& other)
{
	std::cout << "WrongAnimal copy constructor called\n";
	setType(other.getType());
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "WrongAnimal copy assignement operator called\n";
	if (this == &other)
	{
		return *this;
	}
	setType(other.getType());
	return *this;
}

void WrongAnimal::setType(const std::string &type)
{
	this->type = type;
}

std::string WrongAnimal::getType(void) const
{
	return type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal makes WrongAnimal sounds\n";
}
