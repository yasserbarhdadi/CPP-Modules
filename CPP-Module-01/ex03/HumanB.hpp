/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:02:11 by yabarhda          #+#    #+#             */
/*   Updated: 2025/12/18 17:48:13 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Weapon.hpp"

class HumanB {
	private:
	std::string name;
	Weapon* weapon;
	public:
		HumanB(std::string name);
		void setWeapon(Weapon& weapon);
		void attack();	
};
