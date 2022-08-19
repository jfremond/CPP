/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:54:20 by jfremond          #+#    #+#             */
/*   Updated: 2022/08/19 04:49:01 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	this->dogBrain = new Brain();
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
	delete this->dogBrain;
	std::cout << "Dog destructor called" << std::endl;
	return ;
}

void	Dog::makeSound(void) const
{
	std::cout << "Bark bark" << std::endl;
}
