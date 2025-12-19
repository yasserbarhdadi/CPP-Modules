/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:02:02 by yabarhda          #+#    #+#             */
/*   Updated: 2025/12/18 17:44:58 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

// HumanA::HumanA(std::string name, Weapon& weapon)
// {
// 	this->name = name;
// 	this->weapon = weapon;
// }

void HumanA::attack()
{
	std::cout << name + " attacks with their " + weapon.getType() << std::endl;
}
