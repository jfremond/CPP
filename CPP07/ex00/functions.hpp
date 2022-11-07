/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:39:32 by jfremond          #+#    #+#             */
/*   Updated: 2022/11/07 21:52:45 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_HPP
#define FUNCTIONS_HPP

#include <iostream>

template<typename T>
void	swap(T &a, T &b)
{
	T tmp;
	
	tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T const	&min(T const &a, T const &b)
{
	return (a < b ? a : b);
}

template<typename T>
T const	&max(T const &a, T const &b)
{
	return (a > b ? a : b);
}

#endif
