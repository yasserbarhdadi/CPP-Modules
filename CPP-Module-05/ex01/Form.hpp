/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 13:54:55 by yabarhda          #+#    #+#             */
/*   Updated: 2026/05/11 15:16:29 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat;

class Form {
	private:
		const std::string name;
		bool isSigned;
		const int gradeReqtoSign;
		const int gradeReqtoExecute;
	public:
		Form();
		~Form();
		Form(const std::string& name, const int& gradeReqtoSign, const int& gradeReqtoExecute);
		Form(const Form &);
		Form &operator=(const Form&);

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

		std::string getName() const;
		bool getSign() const;
		int getGradeReqtoSign() const;
		int getGradeReqtoExecute() const;
		
		void beSigned(Bureaucrat &b);
};

std::ostream &operator<<(std::ostream &o, const Form &f);