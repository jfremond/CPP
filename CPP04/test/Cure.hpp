/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:58:49 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/12 17:19:45 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"

class Cure : public AMateria
{
	public:
		Cure();
		Cure(Cure const &src);
		Cure	&operator=(Cure const &rhs);
		virtual ~Cure();
		virtual AMateria	*clone() const;
		virtual void		use(ICharacter &target);
};

Cure::Cure() : AMateria()
{
	this->_type = "cure";
	std::cout << "Cure default constructor called" << std::endl;
	return ;
}

Cure::Cure(Cure const &src) : AMateria(src)
{
	this->_type = src.getType();
	std::cout << "Cure copy constructor called" << std::endl;
	return ;
}

Cure		&Cure::operator=(Cure const &rhs)
{
	(*this) = rhs;
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure destructor called" << std::endl;
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

#endif