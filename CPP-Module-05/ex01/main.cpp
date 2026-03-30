/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:56:47 by yabarhda          #+#    #+#             */
/*   Updated: 2026/03/30 16:46:13 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	try {
		Bureaucrat invalid("wow", -1);
	} catch (std::exception &e) {
		std::cout << "invalid bureaucrat: " << e.what() << std::endl;
	}

	try {
		Bureaucrat d;
		std::cout << d.getName() << " at grade " << d.getGrade() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	Bureaucrat alice("Alice", 1);
	Bureaucrat bob("Bob", 150);

	try {
		Form f1("FormA", 50, 25);
		std::cout << f1;
		alice.signForm(f1);
		std::cout << f1;
	} catch (std::exception &e) {
		std::cout << "f1 error: " << e.what() << std::endl;
	}

	try {
		Form f2("FormB", 100, 50);
		std::cout << f2;
		bob.signForm(f2);
		std::cout << f2;
	} catch (std::exception &e) {
		std::cout << "f2 error: " << e.what() << std::endl;
	}

	try {
		Form bad("BadForm", 0, 10);
	} catch (std::exception &e) {
		std::cout << "bad form: " << e.what() << std::endl;
	}

	return 0;
}
