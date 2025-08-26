/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 11:06:23 by yabarhda          #+#    #+#             */
/*   Updated: 2025/08/26 20:12:39 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *z1 = newZombie("Steve");
	Zombie *z2 = newZombie("Tarza");
	Zombie *z3 = newZombie("Simo");
	Zombie *z4 = newZombie("Dave");
	z2->announce();
	randomChump("Crazy Dave");
	delete z1;
	delete z2;
	delete z3;
	delete z4;
	return (0);
}
