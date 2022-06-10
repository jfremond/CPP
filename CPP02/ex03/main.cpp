/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:19:31 by jfremond          #+#    #+#             */
/*   Updated: 2022/06/10 11:23:09 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void)
{
	Point	a(12, 18);
	Point	b(a);
	Point	c(42.42f, 8.4f);
	Point	d;

	std::cout << "a.x : " << a.getX() << " a.y : " << a.getY() << std::endl;	
	std::cout << "b.x : " << b.getX() << " b.y : " << b.getY() << std::endl;
	std::cout << "c.x : " << c.getX() << " c.y : " << c.getY() << std::endl;
	std::cout << "d.x : " << d.getX() << " d.y : " << d.getY() << std::endl;	

	// d = c;
	// std::cout << "d.x : " << d.getX() << " d.y : " << d.getY() << std::endl;	
	return (0);
}