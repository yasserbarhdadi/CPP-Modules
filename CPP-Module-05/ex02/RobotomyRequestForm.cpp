/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 10:48:19 by yabarhda          #+#    #+#             */
/*   Updated: 2026/06/29 14:35:44 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("Robot", 72, 45)
{
	target = "default";
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("Robot", 72, 45)
{
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
	
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
	{
		target = other.target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	
}

void RobotomyRequestForm::doAction() const
{
	srand(time(0));
	std::cout << "** rrrrRRRRRRrrrrr... RRRRRRRR... rrrrr **\n";
	if (!(rand() % 2)) {
		std::cout << "Robotomy failed.\n";
	}
	else {
		std::cout << target << " has been robotomized successfull\n";
	}
}
