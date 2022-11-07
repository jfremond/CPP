/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 22:14:28 by jfremond          #+#    #+#             */
/*   Updated: 2022/11/07 22:28:06 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void	print(T const &value)
{
	std::cout << "value : " << value << std::endl;
}

template<typename T>
void	iter(T *addr, size_t size, void f(T const &value))
{
	for (size_t i = 0; i < size; i++)
	{
		f(addr[i]);
	}
	
}


#endif
