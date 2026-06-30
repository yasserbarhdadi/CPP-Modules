/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 14:30:10 by yabarhda          #+#    #+#             */
/*   Updated: 2026/06/30 10:36:22 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	
}

Intern::~Intern()
{
	
}

Intern::Intern(const Intern &)
{
	
}

Intern &Intern::operator=(const Intern &)
{
	return *this;
}

AForm *Intern::createShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::createRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::createPardon(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(std::string formName, std::string target)
{
	const std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	AForm *(Intern::*formType[3])(std::string) = {
		&Intern::createShrubbery,
		&Intern::createRobotomy,
		&Intern::createPardon
	};
	for (int i = 0; i < 3; i++)
	{
		if (formName == forms[i])
		{
			std::cout << "Intern creates " << formName << "\n";
			return (this->*formType[i])(target);
		}
	}
	std::cout << "Intern cannot create " << formName << "\n";
	return NULL;
}
