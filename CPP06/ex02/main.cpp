/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 20:43:24 by jfremond          #+#    #+#             */
/*   Updated: 2023/01/05 04:48:10 by jfremond         ###   ########.fr       */
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
			new_base = new A;
			break;
		case 2:
			new_base = new B;
			break;
		case 3:
			new_base = new C;
			break;
		default:
			new_base = new Base;
	}
	return new_base;
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << GREEN << "The dynamic_cast to the class A succeded, congrats !" << RESET << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << GREEN << "The dynamic_cast to the class B succeded, congrats !" << RESET << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << GREEN << "The dynamic_cast to the class C succeded, congrats !" << RESET << std::endl;
	else
		std::cout << RED << "Mayday! Mayday! Something went wrong here!" << RESET << std::endl;
}

void	identify(Base &p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << GREEN << "The dynamic_cast to the class A succeded, congrats !" << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << "The dynamic_cast to the class A failed, better luck next time !" << RESET << std::endl;
	}
	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << GREEN << "The dynamic_cast to the class B succeded, congrats !" << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << "The dynamic_cast to the class B failed, better luck next time !" << RESET << std::endl;	
	}
	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << GREEN << "The dynamic_cast to the class C succeded, congrats !" << RESET << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << "The dynamic_cast to the class C failed, better luck next time !" << RESET << std::endl;
	}
}

int	main(void)
{
	std::cout << YELLOW << "GENERATING A NEW BASE" << RESET << std::endl << std::endl;
	Base *new_base = generate();
	
	std::cout << YELLOW << "IDENTIFYING IT USING A POINTER" << RESET << std::endl;
	identify(new_base);
	std::cout << std::endl;
	
	std::cout << YELLOW << "IDENTIFYING IT USING A REFERENCE" << RESET << std::endl;
	identify(*new_base);
	std::cout << std::endl;
	
	delete new_base;
	return (0);
}