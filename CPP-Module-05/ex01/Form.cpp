/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:00:39 by yabarhda          #+#    #+#             */
/*   Updated: 2026/03/30 16:44:25 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default"), isSigned(false), signGrade(1), execGrade(2) {}

Form::Form(const std::string &n, int sGrade, int eGrade) : name(n), isSigned(false),
	signGrade(sGrade), execGrade(eGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw Form::GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw Form::GradeTooLowException();
}

Form::~Form() {}

Form::Form(const Form& other) : name(other.getName()), isSigned(other.getIsSigned()), 
		signGrade(other.getSignGrade()), execGrade(other.getExecGrade()) {}

Form &Form::operator=(const Form &other)
{
	if (this == &other)
	{
		return *this;
	}
	isSigned = other.getIsSigned();
	return *this;
}

std::string Form::getName() const
{
	return name;
}

bool Form::getIsSigned() const
{
	return isSigned;
}

int Form::getSignGrade() const
{
	return signGrade;
}

int Form::getExecGrade() const
{
	return execGrade;
}

char const *Form::GradeTooHighException::what() const throw()
{
	return "Form grade too high";
}

char const *Form::GradeTooLowException::what() const throw()
{
	return "Form grade too low";
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > signGrade)
		throw Form::GradeTooLowException();
	isSigned = true;
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << f.getName() << ", form signed: " << (f.getIsSigned() ? "true" : "false")
	   << ", sign grade " << f.getSignGrade() << ", exec grade " << f.getExecGrade() << ".\n";
	return os;
}
