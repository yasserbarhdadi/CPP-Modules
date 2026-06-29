/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 14:30:10 by yabarhda          #+#    #+#             */
/*   Updated: 2026/06/29 15:33:53 by yabarhda         ###   ########.fr       */
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

ShrubberyCreationForm *Intern::createShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

RobotomyRequestForm *Intern::createRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

PresidentialPardonForm *Intern::createPardon(std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm *makeForm(std::string formName, std::string target)
{
	const std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};

	AForm (*formType[3])(std::string) = {
		createShrubbery,
		createRobotomy,
		createPardon
	};
	for (int i = 0; i < 3; i++)
	{
		if (formName == forms[i])
		{
			
		}
	}
}

/*

"shrubbery creation" → ShrubberyCreationForm
"robotomy request"   → RobotomyRequestForm
"presidential pardon"→ PresidentialPardonForm
*/

// AForm *Intern::makeForm(std::string formName, std::string target);
// {
// 	const std::string forms[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
// 	// void (AForm::*complaint[3])(void) = {
// 	// 	&ShrubberyCreationForm::ShrubberyCreationForm,
// 	// 	&RobotomyRequestForm::RobotomyRequestForm,
// 	// 	&PresidentialPardonForm::PresidentialPardonForm
// 	// };
// 	for (int i = 0; i < 3; i++)
// 	{
// 		if (form == forms[i])
// 		{
// 			(this->*complaint[i])();
// 			return;
// 		}
// 	}
// }
