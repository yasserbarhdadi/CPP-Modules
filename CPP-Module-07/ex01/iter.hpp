/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 20:36:50 by yabarhda          #+#    #+#             */
/*   Updated: 2026/07/31 20:54:09 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename I>
void iter(I *ptr, size_t size, void (*func)(I&))
{
	for (size_t i = 0; i < size; i++) {
		func(ptr[i]);
	}
}

template <typename I>
void iter(I *ptr, size_t size, void (*func)(const I&))
{
	for (size_t i = 0; i < size; i++) {
		func(ptr[i]);
	}
}
