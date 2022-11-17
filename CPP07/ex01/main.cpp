/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 04:33:06 by jfremond          #+#    #+#             */
/*   Updated: 2022/11/17 06:39:14 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int	main()
{
	int			arr_int[] = {1, 2, 3, 4, 5};
	std::string	arr_str[] = {"I like dogs and", "This is a cat and some"};

	std::cout << YELLOW << "ITERATING ON AN ARRAY OF INT" << RESET << std::endl;
	std::cout << YELLOW << "BEFORE INCREMENTING" << RESET << std::endl;
	iter(arr_int, 5, print);
	iter(arr_int, 5, increment);
	std::cout << YELLOW << "AFTER INCREMENTING" << RESET << std::endl;
	iter(arr_int, 5, print);
	std::cout << std::endl;

	std::cout << YELLOW << "ITERATING ON AN ARRAY OF STRING" << RESET << std::endl;
	std::cout << YELLOW << "BEFORE APPENDING" << RESET << std::endl;	
	iter(arr_str, 2, print);
	iter(arr_str, 2, append);
	std::cout << YELLOW << "AFTER APPENDING" << RESET << std::endl;
	iter(arr_str, 2, print);
	std::cout << std::endl;
	
	return (0);
}