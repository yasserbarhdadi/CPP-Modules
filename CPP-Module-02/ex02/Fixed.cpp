/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 05:37:23 by yabarhda          #+#    #+#             */
/*   Updated: 2025/12/30 18:52:21 by yabarhda         ###   ########.fr       */
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
}

Fixed::Fixed(const int value)
{
	fixed_point = value << bits;
}

Fixed::Fixed(const float value)
{
	fixed_point = roundf(value * (1 << bits));
}

Fixed::Fixed(const Fixed& other)
{
	setRawBits(other.getRawBits());
}

Fixed::~Fixed(){
}

Fixed& Fixed::operator=(const Fixed& copy)
{
    if (this == &copy)
	{
        return *this;
	}
	setRawBits(copy.getRawBits());
	return *this;
}

Fixed Fixed::operator+(const Fixed& other) const
{
	Fixed result;
	result.fixed_point = this->fixed_point + other.fixed_point;
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const
{
	Fixed result;
	result.fixed_point = this->fixed_point - other.fixed_point;
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const
{
	Fixed result;
	result.fixed_point = (this->fixed_point * other.fixed_point) >> bits;
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const
{
	Fixed result;
	result.fixed_point = (this->fixed_point << bits) / other.fixed_point;
	return result;
}

bool Fixed::operator>(const Fixed& other) const
{
	return this->fixed_point > other.fixed_point;
}

bool Fixed::operator<(const Fixed& other) const
{
	return this->fixed_point < other.fixed_point;
}

bool Fixed::operator>=(const Fixed& other) const
{
	return this->fixed_point >= other.fixed_point;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return this->fixed_point <= other.fixed_point;
}

bool Fixed::operator==(const Fixed& other) const
{
	return this->fixed_point == other.fixed_point;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return this->fixed_point != other.fixed_point;
}

Fixed& Fixed::operator++()
{
	this->fixed_point += 1;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp(*this);
	this->fixed_point += 1;
	return temp;
}

Fixed& Fixed::operator--()
{
	this->fixed_point -= 1;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed temp(*this);
	this->fixed_point -= 1;
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b)
{
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b)
{
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b)
{
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b)
{
	return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
	os << fixed.toFloat();
	return os;
}
