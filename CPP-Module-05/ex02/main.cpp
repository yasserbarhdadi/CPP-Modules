/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:56:47 by yabarhda          #+#    #+#             */
/*   Updated: 2026/06/30 10:40:23 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::cout << std::boolalpha;

	Bureaucrat daya("lbenj", 1);
	Bureaucrat joe("joe", 34);
	Bureaucrat intern("intern", 150);

	ShrubberyCreationForm shrub("Tree of Wisdom");
	std::cout << shrub;
	try { shrub.beSigned(joe); }
	catch (std::exception &e) { std::cout << "sign error: " << e.what() << '\n'; }
	try { shrub.beSigned(daya); }
	catch (std::exception &e) { std::cout << "sign error: " << e.what() << '\n'; }
	try { shrub.execute(daya); }
	catch (std::exception &e) { std::cout << "exec error: " << e.what() << '\n'; }
	daya.executeForm(shrub);

	RobotomyRequestForm robo("Tesla");
	std::cout << robo;
	try { robo.execute(joe); }
	catch (std::exception &e) { std::cout << "exec without sign: " << e.what() << '\n'; }
	try { robo.beSigned(joe); std::cout << "signed by " << joe.getName() << '\n'; }
	catch (std::exception &e) { std::cout << "sign error: " << e.what() << '\n'; }
	try { robo.execute(joe); }
	catch (std::exception &e) { std::cout << "exec error: " << e.what() << '\n'; }
	daya.executeForm(robo);

	PresidentialPardonForm pardon("Trump");
	std::cout << pardon;
	try { pardon.beSigned(joe); }
	catch (std::exception &e) { std::cout << "sign by joe failed: " << e.what() << '\n'; }
	try { pardon.beSigned(daya); std::cout << "signed by " << daya.getName() << '\n'; }
	catch (std::exception &e) { std::cout << "sign error: " << e.what() << '\n'; }
	try { pardon.execute(intern); }
	catch (std::exception &e) { std::cout << "exec by intern failed: " << e.what() << '\n'; }
	try { pardon.execute(daya); }
	catch (std::exception &e) { std::cout << "exec error: " << e.what() << '\n'; }
	daya.executeForm(pardon);

	return 0;
}
