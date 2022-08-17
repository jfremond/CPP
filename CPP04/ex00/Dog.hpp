/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:13:17 by jfremond          #+#    #+#             */
/*   Updated: 2022/08/17 03:23:13 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
	public:
		Dog(void);
		Dog(Dog const &src);
		Dog	&operator=(Dog const &rhs);
		~Dog(void);
		virtual void	makeSound(void) const;
};

Dog::Dog(void)
{
	this->type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
	return ;
}

Dog::Dog(Dog const &src)
{
	(*this) = src;
	std::cout << "Dog copy constructor called" << std::endl;
	return ;
}

Dog	&Dog::operator=(Dog const &rhs)
{
	this->type = rhs.type;
	return (*this);
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	return ;
}

void	Dog::makeSound(void) const
{
	std::cout << "Bark bark" << std::endl;
}

#endif
