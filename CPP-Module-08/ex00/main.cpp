/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/26 13:04:17 by yabarhda          #+#    #+#             */
/*   Updated: 2026/08/28 18:24:00 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
	std::vector<int> nmb;
	nmb.push_back(10);
	nmb.push_back(20);
	nmb.push_back(30);

	try {
		std::vector<int>::iterator it = easyfind(nmb, 20);
		std::cout << "Found: " << *it << std::endl;
		easyfind(nmb, 42); 
	} catch (const std::exception& e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}