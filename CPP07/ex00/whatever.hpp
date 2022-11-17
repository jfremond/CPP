/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 23:12:38 by jfremond          #+#    #+#             */
/*   Updated: 2022/11/09 03:46:06 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

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
void	swap(T &x, T &y)
{
	T	tmp;
	
	tmp = x;
	x = y;
	y = tmp;
}

template<typename T>
T const	&min(T const &x, T const &y)
{
	return (x < y ? x : y);
}

template<typename T>
T const	&max(T const &x, T const &y)
{
	return (x > y ? x : y);
}

#endif
