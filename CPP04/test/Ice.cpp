/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:49:03 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/12 16:58:07 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria()
{
	this->_type = "ice";
	std::cout << "Ice default constructor called" << std::endl;
	return ;
}

Ice::Ice(Ice const &src) : AMateria(src)
{
	this->_type = src.getType();
	std::cout << "Ice copy constructor called" << std::endl;
	return ;
}

Ice			&Ice::operator=(Ice const &rhs)
{
	(*this) = rhs;
	return (*this);
}

Ice::~Ice()
{
	return ;
}

AMateria	*Ice::clone() const
{
	AMateria	*newIce = new Ice;
	return (newIce);
}

void		AMateria::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
