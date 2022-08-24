/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 02:53:56 by jfremond          #+#    #+#             */
/*   Updated: 2022/08/24 11:19:19 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int	main(void)
{
	const Animal *meta = new Animal();
	const Animal *c = new Cat();
	const Animal *d = new Dog();

	std::cout << std::endl;
	std::cout << ORANGE << "TESTING DYNAMIC LINKAGE" << RESET << std::endl;
	std::cout << "I am an " <<  meta->getType() << std::endl;
	std::cout << "I am a " << c->getType() << std::endl;
	std::cout << "I am a " << d->getType() << std::endl;

	std::cout << std::endl;
	meta->makeSound();
	std::cout << "Cat goes "; c->makeSound();
	std::cout << "Dog goes "; d->makeSound();
	
	std::cout << std::endl;
	delete meta;
	delete c;
	delete d;

	std::cout << std::endl;
	const WrongAnimal	*Wmeta = new WrongAnimal();
	const WrongAnimal	*Wcat = new WrongCat();
	
	std::cout << std::endl;
	std::cout << ORANGE << "TESTING STATIC LINKAGE" << RESET << std::endl;
	std::cout << "I am a " << Wmeta->getType() << std::endl;
	std::cout << "I am a " << Wcat->getType() << std::endl;

	std::cout << std::endl;
	Wmeta->makeSound();
	Wcat->makeSound();
	
	std::cout << std::endl;
	delete Wmeta;
	delete Wcat;
	return (0);
}
