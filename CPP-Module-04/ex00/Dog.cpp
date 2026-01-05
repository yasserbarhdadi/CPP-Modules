/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:23:50 by yabarhda          #+#    #+#             */
/*   Updated: 2026/01/05 17:57:42 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog()
{
	std::cout << "Dog default constructor called\n";
	type = "Dog";
}

Dog::~Dog()
{
	std::cout << "Dog destructor called\n";
}

Dog::Dog(const Dog& other) : Animal(other)
{
	std::cout << "Dog copy constructor called\n";
	setType(other.getType());
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog copy assignement operator called\n";
	if (this == &other)
	{
		return *this;
	}
	setType(other.getType());
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "Dog makes Dog sounds\n";
}
