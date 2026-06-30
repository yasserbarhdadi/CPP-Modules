/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:56:47 by yabarhda          #+#    #+#             */
/*   Updated: 2026/06/30 10:38:47 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main()
{
	std::cout << std::boolalpha;

	Bureaucrat daya("lbenj", 1);

	Intern someIntern;

	AForm *form = someIntern.makeForm("shrubbery creation", "home");
	if (form)
	{
		std::cout << *form;
		try { form->beSigned(daya); }
		catch (std::exception &e) { std::cout << "sign error: " << e.what() << '\n'; }
		try { form->execute(daya); }
		catch (std::exception &e) { std::cout << "exec error: " << e.what() << '\n'; }
		delete form;
	}

	form = someIntern.makeForm("robotomy request", "Bender");
	if (form)
	{
		std::cout << *form;
		try { form->beSigned(daya); }
		catch (std::exception &e) { std::cout << "sign error: " << e.what() << '\n'; }
		try { form->execute(daya); }
		catch (std::exception &e) { std::cout << "exec error: " << e.what() << '\n'; }
		delete form;
	}

	form = someIntern.makeForm("presidential pardon", "Marvin");
	if (form)
	{
		std::cout << *form;
		try { form->beSigned(daya); }
		catch (std::exception &e) { std::cout << "sign error: " << e.what() << '\n'; }
		try { form->execute(daya); }
		catch (std::exception &e) { std::cout << "exec error: " << e.what() << '\n'; }
		delete form;
	}

	form = someIntern.makeForm("unknown form", "none");
	if (!form)
		std::cout << "unknown form request returned null pointer\n";

	return 0;
}
