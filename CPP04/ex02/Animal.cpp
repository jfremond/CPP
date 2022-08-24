/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:52:19 by jfremond          #+#    #+#             */
/*   Updated: 2022/08/24 12:12:13 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

AAnimal::AAnimal(void)
{
	this->type = "Animal";
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
