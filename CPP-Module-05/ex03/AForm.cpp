/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 10:21:43 by yabarhda          #+#    #+#             */
/*   Updated: 2026/06/29 11:41:54 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm() : name("Default"), isSigned(false), gradeReqtoSign(1), gradeReqtoExecute(1) {}

AForm::AForm(const std::string& n, const int& s, const int& e) : name(n), isSigned(false), gradeReqtoSign(s), gradeReqtoExecute(e)
{
	if (s < 1 || e < 1)
		throw AForm::GradeTooHighException();
	if (s > 150 || e > 150)
		throw AForm::GradeTooLowException();	
}

AForm::AForm(const AForm &f) : name(f.getName()), isSigned(f.getSign()),
	gradeReqtoSign(f.getGradeReqtoSign()), gradeReqtoExecute(f.getGradeReqtoExecute()) {}

AForm::~AForm() {}

AForm &AForm::operator=(const AForm &other)
{
	if (this == &other)
	{
		return *this;
	}
	isSigned = other.getSign();
	return *this;
}

std::string AForm::getName() const
{
	return name;
}

bool AForm::getSign() const
{
	return isSigned;
}

int AForm::getGradeReqtoSign() const
{
	return gradeReqtoSign;
}

int AForm::getGradeReqtoExecute() const
{
	return gradeReqtoExecute;
}

void AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() <= gradeReqtoSign)
		isSigned = true;
	else
		throw AForm::GradeTooLowException();
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade too low";
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade too high";
}

const char *AForm::FormNotSignedException::what() const throw()
{
	return "Form not signed";
}

std::ostream& operator<<(std::ostream& os, const AForm& f)
{
	os << f.getName() << " form, is signed? " << f.getSign() << ", grade required to sign is "
	<< f.getGradeReqtoSign() << ", grade required to execute is " << f.getGradeReqtoExecute() << ".\n";
	return os;
}

void AForm::execute(Bureaucrat const & executor) const
{
	if (!isSigned)
		throw AForm::FormNotSignedException();
	if (executor.getGrade() > gradeReqtoExecute)
		throw AForm::GradeTooLowException();
	doAction();
}
