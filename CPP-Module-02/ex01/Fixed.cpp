/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 05:37:12 by yabarhda          #+#    #+#             */
/*   Updated: 2025/12/30 18:47:21 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int Fixed::getRawBits( void ) const
{
	return fixed_point;
}

void Fixed::setRawBits( int const raw )
{
	fixed_point = raw;
}

float Fixed::toFloat( void ) const
{
	return fixed_point / (float)(1 << bits);
}

int Fixed::toInt( void ) const
{
	return fixed_point >> bits;
}

Fixed::Fixed()
{
	fixed_point = 0;
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	fixed_point = value << bits;
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
	fixed_point = roundf(value * (1 << bits));
	std::cout << "Float constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	setRawBits(other.getRawBits());
}

Fixed::~Fixed(){
	std::cout << "Destructor called" << std::endl;
}

Fixed& Fixed::operator=(const Fixed& copy)
{
	std::cout << "Copy assignment operator called" << std::endl;
    if (this == &copy)
	{
        return *this;
	}
	setRawBits(copy.getRawBits());
	return *this;
}

std::ostream& operator<<(std::ostream& stream, const Fixed& fixed)
{
	stream << fixed.toFloat();
	return stream;
}
