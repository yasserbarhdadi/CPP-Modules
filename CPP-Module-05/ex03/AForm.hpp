/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/29 10:21:47 by yabarhda          #+#    #+#             */
/*   Updated: 2026/06/29 11:39:05 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class AForm {
	private:
		const std::string name;
		bool isSigned;
		const int gradeReqtoSign;
		const int gradeReqtoExecute;
	public:
		AForm();
		virtual ~AForm();
		AForm(const std::string& name, const int& gradeReqtoSign, const int& gradeReqtoExecute);
		AForm(const AForm &);
		AForm &operator=(const AForm&);

		class GradeTooHighException : public std::exception
		{
			public:
				const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				const char *what() const throw();			
		};
		class FormNotSignedException : public std::exception
		{
			public:
				const char *what() const throw();
		};

		std::string getName() const;
		bool getSign() const;
		int getGradeReqtoSign() const;
		int getGradeReqtoExecute() const;
		
		void beSigned(Bureaucrat &b);
		
		void execute(Bureaucrat const & executor) const;
		virtual void doAction() const = 0;
};

std::ostream &operator<<(std::ostream &o, const AForm &f);