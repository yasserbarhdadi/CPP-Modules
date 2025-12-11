/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:11:14 by yabarhda          #+#    #+#             */
/*   Updated: 2025/12/11 09:50:38 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#define MAX_CONTACTS 8

class PhoneBook {
	private:
		Contact arr[MAX_CONTACTS];
	public:
		void add_contact();
		void search_contact();
		void print_columns(void);
		std::string get_contact_value(const std::string &prompt);
};
