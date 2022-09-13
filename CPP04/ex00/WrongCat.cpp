/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 02:52:09 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/13 02:52:10 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
	return ;
}

WrongCat::WrongCat(WrongCat const &src) : WrongAnimal(src)
{
	(*this) = src;
	std::cout << "WrongCat copy constructor called" << std::endl;
	return ;
}

WrongCat	&WrongCat::operator=(WrongCat const &rhs)
{
	this->type = rhs.type;
	return (*this);
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat destructor called" << std::endl;
	return ;
}

void WrongCat::makeSound(void) const
{
	std::cout << "WrongCat sounds..." << std::endl;
}
