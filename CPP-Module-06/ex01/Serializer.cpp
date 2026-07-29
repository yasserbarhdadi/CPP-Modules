/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 15:35:37 by yabarhda          #+#    #+#             */
/*   Updated: 2026/07/29 15:38:22 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *ptr)
{
	return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialie(uintptr_t raw)
{
	return reinterpret_cast<Data*>(raw);
}

Serializer::Serializer()
{
	
}

Serializer::~Serializer()
{
	
}

Serializer::Serializer(const Serializer &)
{
	
}

Serializer &Serializer::operator=(const Serializer&)
{
	return *this;
}
