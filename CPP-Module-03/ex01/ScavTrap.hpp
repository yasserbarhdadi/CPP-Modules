/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 09:33:24 by yabarhda          #+#    #+#             */
/*   Updated: 2026/01/05 16:09:36 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& other);
		~ScavTrap();
		ScavTrap &operator=(const ScavTrap&);

		void attack(const std::string& target);
		void guardGate(void);
};
