/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 13:54:52 by yabarhda          #+#    #+#             */
/*   Updated: 2026/05/11 15:16:58 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : name("Default"), isSigned(false), gradeReqtoSign(1), gradeReqtoExecute(1) {}

Form::Form(const std::string& n, const int& s, const int& e) : name(n), isSigned(false), gradeReqtoSign(s), gradeReqtoExecute(e)
{
	if (s < 1 || e < 1)
		throw Form::GradeTooHighException();
	if (s > 150 || e > 150)
		throw Form::GradeTooLowException();	
}

Form::Form(const Form &f) : name(f.getName()), isSigned(f.getSign()),
	gradeReqtoSign(f.getGradeReqtoSign()), gradeReqtoExecute(f.getGradeReqtoExecute()) {}

Form::~Form() {}

Form &Form::operator=(const Form &other)
{
	if (this == &other)
	{
		return *this;
	}
	isSigned = other.getSign();
	return *this;
}

std::string Form::getName() const
{
	return name;
}

bool Form::getSign() const
{
	return isSigned;
}

int Form::getGradeReqtoSign() const
{
	return gradeReqtoSign;
}

int Form::getGradeReqtoExecute() const
{
	return gradeReqtoExecute;
}

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= gradeReqtoSign)
		isSigned = true;
	else
		throw Form::GradeTooLowException();
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

std::ostream& operator<<(std::ostream& os, const Form& f)
{
	os << f.getName() << " form, is signed? " << f.getSign() << ", grade required to sign is "
	<< f.getGradeReqtoSign() << ", grade required to execute is " << f.getGradeReqtoExecute() << ".\n";
	return os;
}
