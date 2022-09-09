/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 07:06:46 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/09 20:35:39 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << GREEN << "Cure default constructor called" << RESET << std::endl;
	return ;
}

Cure::Cure(Cure const &src) : AMateria(src)
{
	(*this) = src;
	std::cout << GREEN << "Cure copy constructor called" << RESET << std::endl;
	return ;
}

Cure			&Cure::operator=(Cure const &rhs)
{
	(void)rhs;
	return (*this);
}

Cure::~Cure()
{
	std::cout << RED << "Cure destructor called" << RESET << std::endl;
	return ;
}

AMateria	*Cure::clone() const
{
	AMateria *newCure = new Cure;
	return (newCure);
}

void		Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
