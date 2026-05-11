/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:56:47 by yabarhda          #+#    #+#             */
/*   Updated: 2026/05/11 15:18:03 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	Form f;
	Bureaucrat bot;
	std::cout << std::boolalpha;
	std::cout << f;
	std::cout << bot;
	Form farm("Wilson", 5, 5);
	std::cout << farm;
	Bureaucrat daya("lbenj", 1);
	std::cout << daya;
	daya.signForm(farm);
	daya.signForm(farm);
	Bureaucrat joe("joe", 34);
	std::cout << joe;
	joe.signForm(farm);
	try
	{
		Bureaucrat b("wow", -1);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
	try
	{
		Bureaucrat b;
		std::cout << b.getName() << " at grade " << b.getGrade() << std::endl;
	}
	catch (std::exception & e)
	{
		std::cout<< e.what() << std::endl;
	}
	return 0;
}
