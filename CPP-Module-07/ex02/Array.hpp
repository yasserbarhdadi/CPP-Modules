/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yabarhda <yabarhda@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 20:39:24 by yabarhda          #+#    #+#             */
/*   Updated: 2026/07/31 21:31:25 by yabarhda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <exception>

template <typename T>

class Array
{
	private:
		unsigned int _size;
		T* ptr;
	public:
		Array() : _size(0), ptr(NULL) {};
		Array(unsigned int n) {
			_size = n;
			ptr = new T[n]();
		}
		~Array() {
			delete[] ptr;
		}
		Array(const Array &o) {
			_size = o._size;
			ptr = new T[_size]();
			for (unsigned int i = 0; i < _size; i++) {
				ptr[i] = o.ptr[i];
			}
		}
		Array &operator=(const Array &o) {
			if (this == &o)
				return *this;
			if (ptr)
				delete[] ptr;
			_size = o._size;
			ptr = new T[_size]();
			for (unsigned int i = 0; i < _size; i++) {
				ptr[i] = o.ptr[i];
			}
			return *this;
		}

		T& operator[](unsigned int n) {
			if (n >= _size)
				throw std::exception();
			return ptr[n];
		}
		const T& operator[](unsigned int n) const {
			if (n >= _size)
				throw std::exception();
			return ptr[n];
		}
		unsigned int size() const {
			return _size;
		}
};