/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 19:56:47 by yabarhda          #+#    #+#             */
/*   Updated: 2026/03/30 14:58:11 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat b("wow", -1);
	}
	catch (std::exception & e)
	{
		std::cout<< e.what() << std::endl;
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
