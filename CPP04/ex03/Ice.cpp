/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:15:22 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/09 20:36:43 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << GREEN << "Ice default constructor called" << RESET << std::endl;
	return ;
}

Ice::Ice(Ice const &src) : AMateria(src)
{
	(*this) = src;
	std::cout << GREEN << "Ice copy constructor called" << RESET << std::endl;
	return ;
}

Ice			&Ice::operator=(Ice const &rhs)
{
	(void)rhs;
	// this->_type = rhs._type;
	return (*this);
}

Ice::~Ice()
{
	std::cout << RED << "Ice destructor called" << RESET << std::endl;
	return ;
}

AMateria	*Ice::clone() const
{
	AMateria *newIce = new Ice;
	return (newIce);
}

void		Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
