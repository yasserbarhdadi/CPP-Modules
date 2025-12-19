/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 16:38:02 by yabarhda          #+#    #+#             */
/*   Updated: 2025/12/18 16:52:43 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int N = 8;
	Zombie* zombies = zombieHorde(N, "3r9sus");
	for (int i = 0; i < N; i++)
		zombies[i].announce();
	delete[] zombies;
	return 0;
}
