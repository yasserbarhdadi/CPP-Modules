/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 09:50:39 by yabarhda          #+#    #+#             */
/*   Updated: 2026/01/04 10:24:17 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	setRawBits(0);
}

Fixed::Fixed(const Fixed &other)
{
	std::cout << "Copy constructor called\n";
	setRawBits(other.getRawBits());
}

Fixed::Fixed(const int i)
{
	std::cout << "Int constructor called\n";
	setRawBits(i << bits);
}

Fixed::Fixed(const float f)
{
	std::cout << "Float constructor called\n";
	setRawBits(roundf(f * (1 << bits)));
}

Fixed &Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called\n";
	if (this == &other)
	{
		return *this;
	}
	setRawBits(other.getRawBits());
	return *this;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called\n";
}

int Fixed::getRawBits(void) const
{
	return fixed_point;
}

void Fixed::setRawBits(int const raw)
{
	fixed_point = raw;	
}

float Fixed::toFloat(void) const
{
	return ((float)fixed_point / (1 << bits));
}

int Fixed::toInt(void) const
{
	return (fixed_point >> bits);
}

std::ostream &operator<<(std::ostream &out, const Fixed &other)
{
	out << other.toFloat();
	return out;
}