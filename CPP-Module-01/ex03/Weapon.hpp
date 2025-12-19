/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 17:02:19 by yabarhda          #+#    #+#             */
/*   Updated: 2025/12/18 17:34:52 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <iostream>

class Weapon {
	private:
		std::string type;
	public:
		Weapon();
		Weapon(std::string type);
		const std::string& getType();
		void setType(std::string type);
};
