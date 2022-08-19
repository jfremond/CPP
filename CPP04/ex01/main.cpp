/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 02:53:56 by jfremond          #+#    #+#             */
/*   Updated: 2022/08/19 05:50:44 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	// const Animal *meta = new Animal();
	// const Animal *c = new Cat();
	// const Animal *d = new Dog();

	// std::cout << std::endl;
	// std::cout << "I am an " <<  meta->getType() << std::endl;
	// std::cout << "I am a " << c->getType() << std::endl;
	// std::cout << "I am a " << d->getType() << std::endl;

	// std::cout << std::endl;
	// meta->makeSound();
	// c->makeSound();
	// d->makeSound();
	
	// std::cout << std::endl;
	// delete meta;
	// delete c;
	// delete d;

	// std::cout << std::endl;
	// const WrongAnimal	*Wmeta = new WrongAnimal();
	// const WrongAnimal	*Wcat = new WrongCat();
	
	// std::cout << std::endl;
	// std::cout << "I am a " << Wmeta->getType() << std::endl;
	// std::cout << "I am a " << Wcat->getType() << std::endl;

	// std::cout << std::endl;
	// Wmeta->makeSound();
	// Wcat->makeSound();
	
	// std::cout << std::endl;
	// delete Wmeta;
	// delete Wcat;

	Brain	brain;
	
	std::cout << brain.getIdea(12) << std::endl;
	std::cout << brain.getAddress(12) << std::endl;
	// Animal	*array[100];
	// for (int i = 0; i < 100; i++)
	// {
	// 	std::cout << "ANIMAL " << i + 1<< ": " << std::endl;
	// 	if (i % 2)
	// 		array[i] = new Dog();
	// 	else
	// 		array[i] = new Cat();
	// }
	// for (int i = 0; i < 100; i++)
	// {
	// 	if (i % 2)
	// 		std::cout << "🐶 : ";
	// 	else
	// 		std::cout << "🐱 : " ;
	// 	array[i]->makeSound();
	// }
	// for (int i = 0; i < 100; i++)
	// {
	// 	std::cout << "ANIMAL " << i + 1<< ": " << std::endl;
	// 	delete array[i];
	// }
	return (0);
}
