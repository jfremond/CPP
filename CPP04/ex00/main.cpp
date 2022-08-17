/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 02:53:56 by jfremond          #+#    #+#             */
/*   Updated: 2022/08/17 04:48:29 by jfremond         ###   ########.fr       */
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

	std::cout << "The type is: " <<  meta->getType() << std::endl;
	std::cout << "The type is: " << c->getType() << std::endl;
	std::cout << "The type is: " << d->getType() << std::endl;

	meta->makeSound();
	c->makeSound();
	d->makeSound();
	delete c;
	delete d;
	delete meta;

	const WrongAnimal	*Wmeta = new WrongAnimal();
	const WrongAnimal	*Wcat = new WrongCat();
	
	std::cout << "The type is: " << Wmeta->getType() << std::endl;
	std::cout << "The type is: " << Wcat->getType() << std::endl;

	Wmeta->makeSound();
	Wcat->makeSound();
	delete Wmeta;
	delete Wcat;
	return (0);
}
