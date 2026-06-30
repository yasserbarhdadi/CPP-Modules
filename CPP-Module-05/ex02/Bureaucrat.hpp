/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:56:49 by yabarhda          #+#    #+#             */
/*   Updated: 2026/06/30 10:36:22 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>
#include <exception>

class AForm;

class Bureaucrat {
	private:
		const std::string name;
		int grade;
	public:
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const std::string &name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat &operator=(const Bureaucrat &);
		
		std::string getName() const;
		int getGrade() const;

		class GradeTooHighException : public std::exception {
			public:
				char const *what() const throw();
		};
		class GradeTooLowException : public std::exception {
			public:
				char const *what() const throw();
		};

		void incrementGrade(void);
		void decrementGrade(void);

		void signForm(AForm &f);
		void executeForm(AForm const &form) const;
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);