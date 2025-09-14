/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 11:25:30 by yabarhda          #+#    #+#             */
/*   Updated: 2025/09/14 16:59:56 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <iostream>

class Weapon {
	private:
		std::string type;
	public:
		Weapon() {}
		Weapon(std::string type) : type(type) {}
		const std::string& getType() const;
		void setType(std::string type);
};
