/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:23:45 by yabarhda          #+#    #+#             */
/*   Updated: 2026/01/06 22:34:53 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat()
{
	std::cout << "Cat default constructor called\n";
	type = "Cat";
	brain = new Brain;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called\n";
	delete brain;
}

Cat::Cat(const Cat& other) : Animal(other)
{
	std::cout << "Cat copy constructor called\n";
	brain = new Brain(*other.brain);
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat copy assignement operator called\n";
	if (this == &other)
	{
		return *this;
	}
	setType(other.getType());
	delete brain;
	brain = new Brain(*other.brain);
	return *this;
}

void Cat::makeSound() const
{
	std::cout << "Cat makes Cat sounds\n";
}
