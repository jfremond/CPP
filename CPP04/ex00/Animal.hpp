/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 02:58:03 by jfremond          #+#    #+#             */
/*   Updated: 2022/08/17 03:34:36 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string	type;
	public:
		Animal(void);
		Animal(Animal const &src);
		Animal	&operator=(Animal const &rhs);
		virtual ~Animal(void);
		virtual void	makeSound(void) const;
		std::string		getType(void) const;
};

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

#endif
