/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 16:45:13 by jfremond          #+#    #+#             */
/*   Updated: 2022/11/28 16:54:09 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define ORANGE  "\033[38;2;255;165;0m"

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>
#include <set>

template<typename T>
typename T::iterator	easyfind(T &cont, int num)
{
	typename T::iterator	res = std::find(cont.begin(), cont.end(), num);
	
	if (res == cont.end())
		throw std::out_of_range("The value is not in the container");
	return (res);	
}
#endif