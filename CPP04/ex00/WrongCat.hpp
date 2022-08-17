/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 04:27:03 by jfremond          #+#    #+#             */
/*   Updated: 2022/08/17 04:45:10 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat(void);
		WrongCat(WrongCat const &src);
		WrongCat	&operator=(WrongCat const &rhs);
		~WrongCat(void);
		void	makeSound(void) const;
};

WrongCat::WrongCat(void)
{
	this->type = "WrongCat";
	std::cout << "WrongCat default constructor called" << std::endl;
	return ;
}

WrongCat::WrongCat(WrongCat const &src)
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

#endif
