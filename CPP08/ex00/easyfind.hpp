/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 07:21:35 by jfremond          #+#    #+#             */
/*   Updated: 2022/12/03 02:29:29 by jfremond         ###   ########.fr       */
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
#include <stdexcept>
#include <list>			// replicates a linked list
#include <vector>		// replicates an array

template<typename T>
typename T::iterator	easyfind(T &cont, int n)
{
	typename T::iterator	res = std::find(cont.begin(), cont.end(), n);
	
	if (res == cont.end())
		throw (std::out_of_range("The number is not in the container"));
	else
		return (res);
}

#endif
