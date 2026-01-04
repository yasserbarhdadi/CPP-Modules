/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 10:27:53 by yabarhda          #+#    #+#             */
/*   Updated: 2026/01/04 18:55:40 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed()
{
	setRawBits(0);
}

Fixed::Fixed(const Fixed &other)
{
	setRawBits(other.getRawBits());
}

Fixed::Fixed(const int i)
{
	setRawBits(i << bits);
}

Fixed::Fixed(const float f)
{
	setRawBits(roundf(f * (1 << bits)));
}

Fixed &Fixed::operator=(const Fixed &other)
{
	if (this == &other)
	{
		return *this;
	}
	setRawBits(other.getRawBits());
	return *this;
}

Fixed::~Fixed() {}

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

Fixed &Fixed::min(Fixed &fixed1, Fixed &fixed2)
{
	return (fixed1.fixed_point > fixed2.fixed_point ? fixed2 : fixed1);
}

const Fixed &Fixed::min(const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1.fixed_point > fixed2.fixed_point ? fixed2 : fixed1);
}

Fixed &Fixed::max(Fixed &fixed1, Fixed &fixed2)
{
	return (fixed1.fixed_point < fixed2.fixed_point ? fixed2 : fixed1);
}

const Fixed &Fixed::max(const Fixed &fixed1, const Fixed &fixed2)
{
	return (fixed1.fixed_point < fixed2.fixed_point ? fixed2 : fixed1);
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed temp;
	temp.fixed_point = fixed_point + other.fixed_point;
	return temp;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed temp;
	temp.fixed_point = fixed_point - other.fixed_point;
	return temp;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed temp;
	temp.fixed_point = (fixed_point * other.fixed_point) >> bits;
	return temp;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed temp;
	temp.fixed_point = (fixed_point << bits) / other.fixed_point;
	return temp;
}

Fixed &Fixed::operator++()
{
	fixed_point++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	fixed_point++;
	return temp;
}

Fixed &Fixed::operator--()
{
	fixed_point--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	fixed_point--;
	return temp;
}

bool Fixed::operator>(const Fixed& other) const
{
	return (getRawBits() > other.getRawBits());
}

bool Fixed::operator<(const Fixed& other) const
{
	return (getRawBits() < other.getRawBits());
}

bool Fixed::operator>=(const Fixed& other) const
{
	return (getRawBits() >= other.getRawBits());
}

bool Fixed::operator<=(const Fixed& other) const
{
	return (getRawBits() <= other.getRawBits());
}

bool Fixed::operator==(const Fixed& other) const
{
	return (getRawBits() == other.getRawBits());
}

bool Fixed::operator!=(const Fixed& other) const
{
	return (getRawBits() != other.getRawBits());
}
