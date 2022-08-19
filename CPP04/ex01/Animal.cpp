/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:52:19 by jfremond          #+#    #+#             */
/*   Updated: 2022/08/18 21:52:49 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	this->type = "Animal";
	std::cout << "Animal default constructor called" << std::endl;
	return ;
}

Animal::Animal(Animal const &src)
{
	(*this) = src;
	std::cout << "Animal copy constructor called" << std::endl;
	return ;
}

Animal	&Animal::operator=(Animal const &rhs)
{
	this->type = rhs.type;
	return (*this);
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor called" << std::endl;
	return ;
}

void	Animal::makeSound(void) const
{
	std::cout << "Random animal sounds..." << std::endl;
}

std::string	Animal::getType(void) const
{
	return (this->type);
}
