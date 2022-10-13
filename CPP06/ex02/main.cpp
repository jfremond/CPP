/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:43:24 by jfremond          #+#    #+#             */
/*   Updated: 2022/10/13 21:51:29 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"

Base	*generate(void)
{
	srand(time(NULL));
	int	randnum = rand() % 3 + 1;
	Base *new_base;
	switch (randnum)
	{
		case 1:
			std::cout << "A" << std::endl;
			new_base = new A;
			break;
		case 2:
			std::cout << "B" << std::endl;
			new_base = new B;
			break;
		case 3:
			std::cout << "C" << std::endl;
			new_base = new C;
			break;
		default:
			std::cout << "ERROR" << std::endl;
			new_base = new Base;
	}
	return new_base;
}

void	identify(Base *p)
{
	if (A	*baseA = dynamic_cast<A *>(p))
		std::cout << "A" << std::endl;
	if (B	*baseB = dynamic_cast<B *>(p))
		std::cout << "B" << std::endl;
	if (C	*baseC = dynamic_cast<C *>(p))
		std::cout << "C" << std::endl;
}

void	identify(Base &p)
{
	try
	{
		A	&baseA = dynamic_cast<A &>(p);
		std::cout << "A" << std::endl;
		(void)baseA;
	}
	catch(const std::exception& e)
	{
		(void)e;
		std::cerr << "Not A" << '\n';
	}
	try
	{
		B	&baseB = dynamic_cast<B &>(p);
		std::cout << "B" << std::endl;
		(void)baseB;
	}
	catch(const std::exception& e)
	{
		(void)e;
		std::cerr << "Not B" << '\n';
	}
	try
	{
		C	&baseC = dynamic_cast<C &>(p);
		std::cout << "C" << std::endl;
		(void)baseC;
	}
	catch(const std::exception& e)
	{
		(void)e;
		std::cerr << "Not C" << '\n';
	}
}

int	main(void)
{
	Base *p = generate();
	identify(p);
	identify(*p);
	delete p;
}