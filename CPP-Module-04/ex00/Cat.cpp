/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:23:45 by yabarhda          #+#    #+#             */
/*   Updated: 2026/01/05 17:57:32 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called\n";
	type = "Cat";
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy constructor called\n";
	setType(other.getType());
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignement operator called\n";
	if (this == &other)
	{
		return *this;
	}
	setType(other.getType());
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Cat makes Cat sounds\n";
}
