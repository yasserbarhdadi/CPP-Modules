/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:11:26 by yabarhda          #+#    #+#             */
/*   Updated: 2025/08/21 17:20:22 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.hpp"

bool Contact::get_status()
{
	return (is_empty);
}

std::string Contact::get_first_name()
{
	return (first_name);
}

std::string Contact::get_last_name()
{
	return (last_name);	
}

std::string Contact::get_nickname()
{
	return (nickname);
}

std::string Contact::get_phone_number()
{
	return (phone_number);
}

std::string Contact::get_dark_secret()
{
	return (dark_secret);
}

void Contact::set_status(bool status)
{
	is_empty = status;
}

void Contact::set_first_name(std::string f_name)
{
	first_name = f_name;
}

void Contact::set_last_name(std::string l_name)
{
	last_name = l_name;
}

void Contact::set_nickname(std::string nick)
{
	nickname = nick;
}

void Contact::set_phone_number(std::string phone_num)
{
	phone_number = phone_num;
}

void Contact::set_dark_secret(std::string secret)
{
	dark_secret = secret;
}
