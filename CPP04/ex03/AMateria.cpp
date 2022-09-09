/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 06:08:26 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/09 20:25:09 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria()
{
	std::cout << GREEN << "AMateria default constructor called" << RESET << std::endl;
	return ;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << GREEN << "AMateria " << this->_type << " string constrctor called" << RESET << std::endl;
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
	return (*this);
}

AMateria::~AMateria()
{
	std::cout << RED << "AMateria destructor called" << RESET << std::endl;
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