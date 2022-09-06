/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:15:22 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/07 00:31:20 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice()
{
	std::cout << "Ice default constructor called" << std::endl;
	this->_type = "ice";
	return ;
}

Ice::Ice(Ice const &src) : AMateria(src)
{
	(*this) = src;
	std::cout << "Ice copy constructor called" << std::endl;
	return ;
}

Ice			&Ice::operator=(Ice const &rhs)
{
	this->_type = rhs._type;
	return (*this);
}

Ice::~Ice()
{
	std::cout << "Ice destructor called" << std::endl;
	return ;
}

AMateria	*Ice::clone() const
{
	AMateria *newIce = new Ice;
	return (newIce);
}

void		Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << "*" << std::endl;
}
