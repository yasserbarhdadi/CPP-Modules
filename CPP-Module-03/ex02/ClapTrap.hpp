/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:33:16 by yabarhda          #+#    #+#             */
/*   Updated: 2026/01/05 16:10:09 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class ClapTrap {
	protected:
		std::string name;
		unsigned int HP;
		unsigned int EP;
		unsigned int AD;
	public:
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other);
		~ClapTrap();
		ClapTrap &operator=(const ClapTrap&);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);
		
		void setHP(unsigned int value);
		void setEP(unsigned int value);
		void setAD(unsigned int value);
		unsigned int getHP(void) const;
		unsigned int getEP(void) const;
		unsigned int getAD(void) const;
};
