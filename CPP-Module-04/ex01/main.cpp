/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 17:12:52 by yabarhda          #+#    #+#             */
/*   Updated: 2026/01/06 22:51:40 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	int max_animals = 10;
	const Animal* animals[max_animals];

	for (int i = 0; i < max_animals / 2; i++)
		animals[i] = new Dog;
	for (int i = max_animals / 2; i < max_animals; i++)
		animals[i] = new Cat;
	for (int i = 0; i < max_animals; i++)
		animals[i]->makeSound();
	for (int i = 0; i < max_animals; i++)
		delete animals[i];
	return 0;
}