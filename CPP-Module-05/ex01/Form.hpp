/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/30 15:00:41 by yabarhda          #+#    #+#             */
/*   Updated: 2026/03/30 16:44:25 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Bureaucrat;

class Form {
	private:
		const std::string name;
		bool isSigned;
		const int signGrade;
		const int execGrade;
	public:
		Form();
		Form(const std::string &name, int signGrade, int execGrade);
		~Form();
		Form(const Form& other);
		Form &operator=(const Form &other);

		std::string getName() const;
		bool		getIsSigned() const;
		int			getSignGrade() const;
		int			getExecGrade() const;

		void beSigned(Bureaucrat const &bureaucrat);

		class GradeTooHighException : public std::exception {
			public:
				char const *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				char const *what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& f);
