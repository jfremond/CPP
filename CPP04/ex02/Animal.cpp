/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 02:56:27 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/13 02:56:28 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal(void) : type("Animal")
{
	std::cout << "Animal default constructor called" << std::endl;
	return ;
}

AAnimal::AAnimal(AAnimal const &src)
{
	(*this) = src;
	std::cout << "Animal copy constructor called" << std::endl;
	return ;
}

AAnimal	&AAnimal::operator=(AAnimal const &rhs)
{
	this->type = rhs.type;
	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << "Animal destructor called" << std::endl;
	return ;
}

void	AAnimal::makeSound(void) const
{
	std::cout << "Random animal sounds..." << std::endl;
}

std::string	AAnimal::getType(void) const
{
	return (this->type);
}
