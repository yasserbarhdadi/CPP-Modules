/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 20:29:06 by yabarhda          #+#    #+#             */
/*   Updated: 2026/07/31 20:35:39 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename S>
void swap(S &a, S &b)
{
	S tmp = a;
	a = b;
	b = tmp;
}

template <typename MI>
MI min(MI a, MI b)
{
	return (a > b ? b : a);
}

template <typename MX>
MX max(MX a, MX b)
{
	return (a > b ? a : b);
}