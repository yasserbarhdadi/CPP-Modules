/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 14:30:08 by yabarhda          #+#    #+#             */
/*   Updated: 2026/06/29 15:21:11 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	public:
		Intern();
		~Intern();
		Intern(const Intern &);
		Intern &operator=(const Intern &);

		AForm *makeForm(std::string formName, std::string target);
		ShrubberyCreationForm *createShrubbery(std::string target);
		RobotomyRequestForm *createRobotomy(std::string target);
		PresidentialPardonForm *createPardon(std::string target);
};
