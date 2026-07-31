/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 20:36:48 by yabarhda          #+#    #+#             */
/*   Updated: 2026/07/31 20:50:47 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "iter.hpp"

template <typename T>
void print(T const & x) {
    std::cout << x << std::endl;
}

int main() {
    int arr[] = {1, 2, 3, 4};
    ::iter(arr, 4, print<int>);

    std::string sArr[] = {"test1", "test2", "test3"};
    ::iter(sArr, 3, print<std::string>);

    return 0;
}
