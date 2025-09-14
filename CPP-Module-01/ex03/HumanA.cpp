/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 11:25:17 by yabarhda          #+#    #+#             */
/*   Updated: 2025/09/14 17:02:21 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

void HumanA::attack()
{
	std::cout << getName() + " attacks with their " + weapon.getType() << std::endl;
}

void HumanA::setName(std::string name)
{
	this->name = name;
}

std::string HumanA::getName() const
{
	return (name);	
}
