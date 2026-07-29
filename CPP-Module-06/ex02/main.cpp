/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 15:45:26 by yabarhda          #+#    #+#             */
/*   Updated: 2026/07/29 16:56:56 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main()
{
	srand(time(NULL));

	Base *ranObj = generate();
	std::cout << "Pointer: ";
	identify(ranObj);
	std::cout << "Reference: ";
	identify(*ranObj);
	delete ranObj;
	return 0;
}