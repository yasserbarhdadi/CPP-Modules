/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 10:48:13 by yabarhda          #+#    #+#             */
/*   Updated: 2026/06/29 12:15:19 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("President", 25, 5)
{
	target = "default";
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("President", 25, 5)
{
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
	
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this != &other)
	{
		target = other.target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	
}

void PresidentialPardonForm::doAction() const
{
	std::cout << target << " has been pardoned by Zaphod Beeblebrox.\n";
}
