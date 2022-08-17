/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:04:22 by jfremond          #+#    #+#             */
/*   Updated: 2022/08/17 03:34:40 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
	public:
		Cat(void);
		Cat(Cat const &src);
		Cat	&operator=(Cat const &rhs);
		~Cat(void);
		virtual void	makeSound(void) const;
};

Cat::Cat(void)
{
	this->type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
	return ;
}

Cat::Cat(Cat const &src)
{
	(*this) = src;
	std::cout << "Cat copy constructor called" << std::endl;
	return ;
}

Cat	&Cat::operator=(Cat const &rhs)
{
	this->type = rhs.type;
	return (*this);	
}

Cat::~Cat(void)
{
	std::cout << "Cat destructor called" << std::endl;
	return ;
}

void	Cat::makeSound(void) const
{
	std::cout << "Meow meow" << std::endl;
}

#endif
