/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:19:31 by jfremond          #+#    #+#             */
/*   Updated: 2022/06/10 13:23:42 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	Point	a(5, 7);
	Point	b(-8, 2);
	Point	c(3, -11);
	Point	d(4.89f, 6);		// On edge
	Point	e(-8, 2);		 	// vertex
	Point	f(-2, -2);			// In the triangle
	
	if (bsp(a, b, c, d) == true)
		std::cout << "The point d is in the triangle" << std::endl;
	else
		std::cout << "The point d is not in the triangle" << std::endl;
	
	if (bsp(a, b, c, e) == true)
		std::cout << "The point e is in the triangle" << std::endl;
	else
		std::cout << "The point e is not in the triangle" << std::endl;
		
	if (bsp(a, b, c, f) == true)
		std::cout << "The point f is in the triangle" << std::endl;
	else
		std::cout << "The point f is not in the triangle" << std::endl;
	
	return (0);
}