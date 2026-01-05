/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:42:44 by yabarhda          #+#    #+#             */
/*   Updated: 2026/01/05 17:58:15 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "WrongCat default constructor called\n";
	type = "WrongCat";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called\n";
}

WrongCat::WrongCat(const WrongCat& other) : Animal(other)
{
	std::cout << "WrongCat copy constructor called\n";
	setType(other.getType());
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat copy assignement operator called\n";
	if (this == &other)
	{
		return *this;
	}
	setType(other.getType());
	return *this;
}

void WrongCat::makeSound() const
{
	std::cout << "WrongCat makes WrongCat sounds\n";
}
