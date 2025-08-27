/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 20:16:07 by yabarhda          #+#    #+#             */
/*   Updated: 2025/08/27 10:21:00 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = 10;
	Zombie *zombie = zombieHorde(N, "Crazy Dave");
	for (int i = 0; i < N; i++)
		zombie[i].announce();
	delete[] zombie;
	return (0);
}
