/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:36:26 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/12 17:19:05 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() : _type("unknown")
{
	std::cout << "AMateria default constructor called" << std::endl;
	return ;
}

AMateria::AMateria(std::string const type) : _type(type)
{
	std::cout << "AMateria " << this->_type << " string constructor called" << std::endl;
	return ;
}

AMateria::AMateria(AMateria const &src) : _type(src.getType())
{
	std::cout << "AMateria copy constructor called" << std::endl;
	return ;
}

AMateria	&AMateria::operator=(AMateria const &rhs)
{
	(*this) = rhs;
	return (*this);	
}

AMateria::~AMateria()
{
	std::cout << "AMateria " << this->_type << " destructor called" << std::endl;
	return ;
}

std::string const	&AMateria::getType() const
{
	return (this->_type);
}

void	AMateria::use(ICharacter &target)
{
	std::cout << this->_type << " materia used against " << target.getName() << std::endl;
}
