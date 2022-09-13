/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:49:03 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/13 00:44:05 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice default constructor called" << std::endl;
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
	(void)rhs;
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

void		Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
