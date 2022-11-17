/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 04:29:41 by jfremond          #+#    #+#             */
/*   Updated: 2022/11/11 18:49:41 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define ORANGE  "\033[38;2;255;165;0m"

#include <iostream>

template<typename T>
void	print(T &value)
{
	std::cout << ORANGE << "value : " << RESET << value << std::endl;
}

template<typename T>
void	increment(T &value)
{
	value++;
}

template<typename T>
void	append(T &value)
{
	value += " food";
}

template<typename T>
void	iter(T *addr, size_t size, void f(T &value))
{
	for (size_t i = 0; i < size; i++)
		f(addr[i]);
}

#endif