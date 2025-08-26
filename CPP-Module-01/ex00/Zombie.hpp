/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/26 10:36:57 by yabarhda          #+#    #+#             */
/*   Updated: 2025/08/26 11:34:05 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Zombie {
	private:
		std::string name;
	public:
		void announce(void);
		void set_name(std::string name);
		std::string get_name(void);
		~Zombie();
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);
