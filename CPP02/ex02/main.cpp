/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:19:31 by jfremond          #+#    #+#             */
/*   Updated: 2022/06/10 17:12:21 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int	main(void)
{	
	Fixed	a(12.9f);
	Fixed	b(10.4f);

	std::cout << "\033[33mFirst values of a and b :\033[0m" << std::endl;
	std::cout << "Value of a : " << a << std::endl;
	std::cout << "Value of b : " << b << std::endl << std::endl;

	std::cout << "\033[33mTest comparisons : "
		<<  "a > b, a < b, a >= b, a <= b, a == b, a != b\033[0m" << std::endl;
	std::cout << "Value of a : " << a << std::endl;
	std::cout << "Value of b : " << b << std::endl;
	std::cout << "Value of a > b : " << (a > b) << std::endl;
	std::cout << "Value of a < b : " << (a < b) << std::endl;
	std::cout << "Value of a >= b : " << (a >= b) << std::endl;
	std::cout << "Value of a <= b : " << (a <= b) << std::endl;
	std::cout << "Value of a == b : " << (a == b) << std::endl;
	std::cout << "Value of a != b : " << (a != b) << std::endl << std::endl;
	
	std::cout << "\033[33mTest arithmetic operations : "
		<< "a + 56, a - 45.2f, b * 3.4f, b / 6\033[0m" << std::endl;
	std::cout << "Value of a : " << a << std::endl;
	std::cout << "Value of a + 56 : " << a + 56 << std::endl;
	std::cout << "Value of a : " << a << std::endl;
	std::cout << "Value of a - 45.2f : " << a - 45.2f << std::endl;
	std::cout << "Value of a : " << a << std::endl;
	std::cout << "Value of b : " << b << std::endl;
	std::cout << "Value of b * 3.4f : " << b * 3.4f << std::endl;
	std::cout << "Value of b : " << b << std::endl;
	std::cout << "Value of b / 6 : " << b / 6 << std::endl;
	std::cout << "Value of b : " << b << std::endl << std::endl;
	
	std::cout << "\033[33mTest incrementation : "
		<< "++a, a++\033[0m" << std::endl;
	std::cout << "Value of a : " << a << std::endl;
	std::cout << "Value of ++a : " << ++a << std::endl;
	std::cout << "Value of a : " << a << std::endl;
	std::cout << "Value of a++ : " << a++ << std::endl;
	std::cout << "Value of a : " << a << std::endl << std::endl;

	std::cout << "\033[33mTest decrementation : "
		<< "--b, b--\033[0m" << std::endl;
	std::cout << "Value of b : " << b << std::endl;
	std::cout << "Value of --b : " << --b << std::endl;
	std::cout << "Value of b : " << b << std::endl;
	std::cout << "Value of b-- : " << b-- << std::endl;
	std::cout << "Value of b : " << b << std::endl << std::endl;

	std::cout << "\033[33mTest min and max : "
		<< "min(a, b), max(a, b)\033[0m" << std::endl;
	std::cout << "Value of a : " << a << std::endl;
	std::cout << "Value of b : " << b << std::endl;
	std::cout << "Value of min(a, b) : " << Fixed::min(a, b) << std::endl;
	std::cout << "Value of max(a, b) : " << Fixed::max(a, b) << std::endl << std::endl;
	
	return (0);
}