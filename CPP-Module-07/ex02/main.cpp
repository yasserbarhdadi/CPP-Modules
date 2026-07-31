/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 20:39:27 by yabarhda          #+#    #+#             */
/*   Updated: 2026/07/31 21:29:49 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main() {
    Array<int> emptyArray;
    std::cout << emptyArray.size() << std::endl;

    Array<int> arr(5);
    for (unsigned int i = 0; i < 5; i++) {
        arr[i] = i * 10;
    }

    Array<int> copyArr(arr);
    copyArr[0] = 999;

    std::cout << arr[0] << std::endl;
    std::cout << copyArr[0] << std::endl;

    try {
        arr[10] = 5;
    } catch (std::exception& e) {
        std::cout << "Exception caught" << std::endl;
    }

    return 0;
}