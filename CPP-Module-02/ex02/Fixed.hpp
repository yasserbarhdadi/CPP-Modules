/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 10:27:56 by yabarhda          #+#    #+#             */
/*   Updated: 2026/01/04 18:54:45 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cmath>

class Fixed {
	private:
		int fixed_point;
		static const int bits = 8;
	public:
		Fixed();
		~Fixed();
		Fixed(const Fixed &other);
		Fixed &operator=(const Fixed &other);
		Fixed(const int i);
		Fixed(const float f);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;

		bool operator>(const Fixed&) const;
		bool operator<(const Fixed&) const;
		bool operator>=(const Fixed&) const;
		bool operator<=(const Fixed&) const;
		bool operator==(const Fixed&) const;
		bool operator!=(const Fixed&) const;

		Fixed operator+(const Fixed&) const;
		Fixed operator-(const Fixed&) const;
		Fixed operator*(const Fixed&) const;
		Fixed operator/(const Fixed&) const;

		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);

		static Fixed &min(Fixed &fixed1, Fixed &fixed2);
		static const Fixed &min(const Fixed &fixed1, const Fixed &fixed2);
		static Fixed &max(Fixed &fixed1, Fixed &fixed2);
		static const Fixed &max(const Fixed &fixed1, const Fixed &fixed2);
};

std::ostream &operator<<(std::ostream &out, const Fixed &other);