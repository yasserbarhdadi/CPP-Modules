/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 18:04:53 by yabarhda          #+#    #+#             */
/*   Updated: 2026/01/06 22:10:39 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain default constructor called\n";
	for (int i = 0; i < MAX_IDEAS; i++)
	{
		setIdea("Placeholder idea", i);
	}
}

Brain::~Brain()
{
	std::cout << "Brain destructor called\n";
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain copy constructor called\n";
	for (int i = 0; i < MAX_IDEAS; i++)
	{
		setIdea(other.getIdea(i), i);
	}
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain copy assignement operator called\n";
	if (this == &other)
	{
		return *this;
	}
	for (int i = 0; i < MAX_IDEAS; i++)
	{
		setIdea(other.getIdea(i), i);
	}
	return *this;
}

void Brain::setIdea(const std::string &idea, int index)
{
	ideas[index] = idea;
}

std::string Brain::getIdea(int index) const
{
	if (index < 0 || index >= MAX_IDEAS)
		return "Index out of range";
	return ideas[index];
}
