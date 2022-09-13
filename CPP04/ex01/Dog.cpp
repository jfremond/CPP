/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 02:57:10 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/13 03:11:22 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	this->_dogBrain = new Brain;
	std::cout << "Dog default constructor called" << std::endl;
	return ;
}

Dog::Dog(Dog const &src) : Animal(src)
{
	(*this) = src;
	std::cout << "Dog copy constructor called" << std::endl;
	return ;
}

Dog	&Dog::operator=(Dog const &rhs)
{
	this->type = rhs.type;
	this->_dogBrain = new Brain;
	*(this->_dogBrain) = *rhs._dogBrain;
	return (*this);
}

Dog::~Dog(void)
{
	delete this->_dogBrain;
	std::cout << "Dog destructor called" << std::endl;
	return ;
}

void	Dog::makeSound(void) const
{
	std::cout << "woof" << std::endl;
}

std::string		Dog::getIdea(int index)
{
	return (this->_dogBrain->getIdea(index));
}

void	Dog::setIdea(std::string str, int index)
{
	this->_dogBrain->setIdea(str, index);
}
