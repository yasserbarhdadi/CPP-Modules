/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 13:24:30 by yabarhda          #+#    #+#             */
/*   Updated: 2026/09/01 10:55:29 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <exception>
#include <iterator>
#include <algorithm>
#include <climits>

class Span {
	private:
		unsigned int _maxElements;
		std::vector<int> _numbers;

	public:
		Span();
		Span(unsigned int n);
		Span(const Span& other);
		Span& operator=(const Span& other);
		~Span();

		void addNumber(int number);
		int shortestSpan() const;
		int longestSpan() const;

		class SpanFullException : public std::exception
		{
			public:
				virtual const char* what() const throw() {
					return "Span is full";
				}
		};

		class NoSpanFoundException : public std::exception
		{
			public:
				virtual const char* what() const throw() {
					return "Not enough elements to find a span";
				}
		};

		template <typename Iterator>
		void addNumbers(Iterator begin, Iterator end) {
		    std::ptrdiff_t distance = std::distance(begin, end);
		    if (_numbers.size() + distance > _maxElements)
		        throw SpanFullException();
		    _numbers.insert(_numbers.end(), begin, end);
		}
};