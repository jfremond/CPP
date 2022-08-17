/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 04:09:19 by jfremond          #+#    #+#             */
/*   Updated: 2022/08/17 04:41:55 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const &src);
		WrongAnimal	&operator=(WrongAnimal const &rhs);
		~WrongAnimal(void);
		void	makeSound(void) const;
		std::string getType(void) const;
};

WrongAnimal::WrongAnimal(void)
{
	this->type = "WrongAnimal";
	std::cout << "WrongAnimal default constructor called" << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src)
{
	(*this) = src;
	std::cout << "WrongAnimal copy consructor called" << std::endl;
	return ;
}

WrongAnimal	&WrongAnimal::operator=(WrongAnimal const &rhs)
{
	this->type = rhs.type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor called" << std::endl;
	return ;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "Random WrongAnimal sounds..." << std::endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (this->type);
}

#endif
