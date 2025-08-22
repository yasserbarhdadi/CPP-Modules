/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/20 13:06:38 by yabarhda          #+#    #+#             */
/*   Updated: 2025/08/22 18:36:29 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int ac, char **av)
{
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
	else
	{
		for (int i = 1; av[i]; i++)
		{
			for (int j = 0; av[i][j]; j++)
			{
				if (isalpha(av[i][j]))
					std::cout << (char)toupper(av[i][j]);
				else
					std::cout << av[i][j];
			}
		}
		std::cout << std::endl;
	}
	return (0);
}
