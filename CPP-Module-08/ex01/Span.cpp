/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 13:24:20 by yabarhda          #+#    #+#             */
/*   Updated: 2026/09/01 10:55:13 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>
#include <climits>

Span::Span() : _maxElements(0) {}

Span::Span(unsigned int n) : _maxElements(n) {}

Span::Span(const Span& other) : _maxElements(other._maxElements), _numbers(other._numbers) {}

Span& Span::operator=(const Span& other)
{
	if (this != &other) {
		_maxElements = other._maxElements;
		_numbers = other._numbers;
	}
	return *this;
}

Span::~Span() {}

void Span::addNumber(int number)
{
	if (_numbers.size() >= _maxElements)
		throw SpanFullException();
	_numbers.push_back(number);
}

int Span::shortestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanFoundException();
	
	std::vector<int> sorted(_numbers);
	std::sort(sorted.begin(), sorted.end());
	
	int shortest = INT_MAX;
	for (std::vector<int>::iterator it = sorted.begin(); it != sorted.end() - 1; ++it) {
		int span = *(it + 1) - *it;
		if (span < shortest)
			shortest = span;
	}
	
	return shortest;
}

int Span::longestSpan() const
{
	if (_numbers.size() < 2)
		throw NoSpanFoundException();
	
	std::vector<int>::const_iterator min_it = std::min_element(_numbers.begin(), _numbers.end());
	std::vector<int>::const_iterator max_it = std::max_element(_numbers.begin(), _numbers.end());
	
	return *max_it - *min_it;
}

