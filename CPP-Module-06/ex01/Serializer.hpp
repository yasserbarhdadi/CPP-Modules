/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 14:04:54 by yabarhda          #+#    #+#             */
/*   Updated: 2026/07/29 15:42:11 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <stdint.h>

typedef struct Data {
	std::string name;
	int id;	
}	Data;

class Serializer
{
	public:
		static uintptr_t serialize(Data *ptr);
		static Data* deserialie(uintptr_t raw);
	private:
		Serializer();
		~Serializer();
		Serializer(const Serializer &);
		Serializer &operator=(const Serializer&);
};