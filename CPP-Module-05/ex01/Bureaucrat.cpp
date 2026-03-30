/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:56:44 by yabarhda          #+#    #+#             */
/*   Updated: 2026/03/30 16:44:25 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string &n, int g) : name(n), grade(g)
{
	if (g < 1)
		throw Bureaucrat::GradeTooHighException();
	if (g > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat() : name("Default"), grade(1) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.getName()),
		grade(other.getGrade()) {}
		
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this == &other)
	{
		return *this;
	}
	grade = other.getGrade();
	return *this;
}

std::string Bureaucrat::getName() const
{
	return name;
}

int Bureaucrat::getGrade() const
{
	return grade;
}

char const *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

char const *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

void Bureaucrat::incrementGrade(void)
{
	if (grade == 1)
		throw Bureaucrat::GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if (grade == 150)
		throw Bureaucrat::GradeTooLowException();
	grade++;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
	os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n";
	return os;
}

void Bureaucrat::signForm(Form& form)
{
	try {
		form.beSigned(*this);
		std::cout << name << " signed " << form.getName() << std::endl;
	}
	catch (std::exception & e) {
		std::cout << name << " couldn't sign " << form.getName() << " because " << e.what() << "." << std::endl;
	}
}
