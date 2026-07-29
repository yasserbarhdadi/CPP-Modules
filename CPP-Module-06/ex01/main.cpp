/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 14:04:33 by yabarhda          #+#    #+#             */
/*   Updated: 2026/07/29 15:41:52 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data dt;
	dt.name = "Steve";
	dt.id = 1337;

	std::cout << "OG ADDR: " << &dt << "\n";
	std::cout << "OG NAME: " << dt.name << "\n";

	uintptr_t raw_ptr = Serializer::serialize(&dt);
	std::cout << "Serialized int: " << raw_ptr << "\n";

	Data* des_data = Serializer::deserialie(raw_ptr);
	std::cout << "Deserialized ADDR: " << des_data << "\n";
	std::cout << "Deserialized NAME: " << des_data->name << std::endl;
	return 0;
}