/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 06:08:26 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/09 03:02:15 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << "AMateria default constructor called" << std::endl;
	return ;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << "AMateria " << this->_type << " string constrctor called" << std::endl;
	return ;
}

AMateria::AMateria(AMateria const &src) : _type(src._type)
{
	(*this) = src;
	std::cout << "AMateria copy constructor called" << std::endl;
	return ;
}

AMateria	&AMateria::operator=(AMateria const &rhs)
{
	(void)rhs;
//	this->_type = rhs._type;
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << "AMateria destructor called" << std::endl;
}

std::string const	&AMateria::getType(void) const
{
	return (this->_type);
}

void	AMateria::use(ICharacter &target)
{
	// ! Very wrong if you see this
	std::cout << this->_type << " AMateria uses something against " << target.getName() << std::endl;
}