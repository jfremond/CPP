/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:49:16 by jfremond          #+#    #+#             */
/*   Updated: 2022/11/16 22:59:13 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define ORANGE  "\033[38;2;255;165;0m"

#include <iostream>
#include <stdexcept>
#include <cstdlib>

template<class T>
class Array
{
	private:
		int				_size;
		T				*_array;
	public:
		Array<T>() : _size(0), _array(new T[_size]) {};
		Array<T>(int n) : _size(n)
		{
			if (_size < 0)
				throw std::out_of_range("The index is out of range");
			_array = new T[_size];
		}
		Array<T>(Array<T> const &src) : _size(src._size), _array(new T[_size])
		{
			for (int i = 0; i < _size; i++)
				_array[i] = src._array[i];
		}
		Array<T>		&operator=(Array<T> const &rhs)
		{
			delete[] _array;
			_size = rhs._size;
			_array = new T[_size];
			for (int i = 0; i < _size; i++)
				_array[i] = rhs._array[i];
			return (*this);
		}
		T				&operator[](int i)
		{
			if (i < 0 || i >= _size)
				throw std::out_of_range("The index is out of range");
			return (_array[i]);
		}
		int	size() { return (_size); }
		~Array<T>() { delete[] _array; }
};

#endif
