/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 21:53:46 by jfremond          #+#    #+#             */
/*   Updated: 2022/08/24 11:32:34 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	this->_catBrain = new Brain;
	std::cout << "Cat default constructor called" << std::endl;
	return ;
}

Cat::Cat(Cat const &src) : Animal(src)
{
	(*this) = src;
	std::cout << "Cat copy constructor called" << std::endl;
	return ;
}

Cat	&Cat::operator=(Cat const &rhs)
{
	this->type = rhs.type;
	this->_catBrain = new Brain;
	
	*(this->_catBrain) = *rhs._catBrain;
	return (*this);	
}

Cat::~Cat(void)
{
	delete this->_catBrain;
	std::cout << "Cat destructor called" << std::endl;
	return ;
}

void	Cat::makeSound(void) const
{
	std::cout << "meow" << std::endl;
}
