/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 02:53:56 by jfremond          #+#    #+#             */
/*   Updated: 2022/08/23 05:58:16 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include "Brain.hpp"

int	main(void)
{
	std::cout << RED << "Test 1 : Create and fill an array of Animal objects." << std::endl;
	std::cout << "Half of them are Dog objects, the other half are Cat objects." << RESET << std::endl << std::endl;
	
	Animal	*array[10];
	std::cout << ORANGE << "Construction of the array" << RESET << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << YELLOW << "ANIMAL " << i + 1 << " : " << RESET << std::endl;
		if (i % 2)
			array[i] = new Cat;
		else
			array[i] = new Dog;
	}

	std::cout << std::endl;
	std::cout << ORANGE << "Calling the makeSound function" << RESET << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << YELLOW << "ANIMAL " << i + 1 << " : " << RESET;
		std::cout << array[i]->getType() << " goes ";
		array[i]->makeSound();
	}
	std::cout << std::endl;
	std::cout << ORANGE << "Destruction of the array" << RESET << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << YELLOW << "ANIMAL " << i + 1 << " : " << RESET << std::endl;
		delete array[i];
	}
	std::cout << std::endl;
	std::cout << RED << "Test 2 : Test that the copies are deep copies" << RESET << std::endl;
	
	Dog	dog;
	Dog	cpy = dog;
	std::cout << dog.getIdea(0) << std::endl;
	std::cout << cpy.getIdea(0) << std::endl;
	std::cout << dog.getAddress() << std::endl;
	std::cout << cpy.getAddress() << std::endl;
	dog.setIdea("I love Rock n Roll", 0);
	std::cout << dog.getIdea(0) << std::endl;
	std::cout << cpy.getIdea(0) << std::endl;
	std::cout << dog.getAddress() << std::endl;
	std::cout << cpy.getAddress() << std::endl;
	return (0);
}
