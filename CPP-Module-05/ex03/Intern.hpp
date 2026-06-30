/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 14:30:08 by yabarhda          #+#    #+#             */
/*   Updated: 2026/06/30 10:16:39 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		AForm *createShrubbery(std::string target);
		AForm *createRobotomy(std::string target);
		AForm *createPardon(std::string target);
	public:
		Intern();
		~Intern();
		Intern(const Intern &);
		Intern &operator=(const Intern &);

		AForm *makeForm(std::string formName, std::string target);
};
