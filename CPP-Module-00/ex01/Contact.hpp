/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 15:11:19 by yabarhda          #+#    #+#             */
/*   Updated: 2025/08/21 17:19:19 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

struct Contact {
	private:
		bool		is_empty = true;
		std::string first_name;
		std::string last_name;
		std::string nickname;
		std::string phone_number;
		std::string dark_secret;
	public:
		bool		get_status();
		std::string get_first_name();
		std::string get_last_name();
		std::string get_nickname();
		std::string get_phone_number();
		std::string get_dark_secret();

		void		set_status(bool status);
		void		set_first_name(std::string f_name);
		void		set_last_name(std::string l_name);
		void		set_nickname(std::string nick);
		void		set_phone_number(std::string phone_num);
		void		set_dark_secret(std::string secret);
};

#endif
