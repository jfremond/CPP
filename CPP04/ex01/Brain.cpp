/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 00:22:27 by jfremond          #+#    #+#             */
/*   Updated: 2022/08/19 05:49:21 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "A new idea...";
	std::cout << "Brain default constructor called" << std::endl;
	return ;
}

Brain::Brain(Brain const &src)
{
	(*this) = src;
	std::cout << "Brain copy constructor called" << std::endl;
	return ;
}

Brain	&Brain::operator=(Brain const &rhs)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = rhs.ideas[i];
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
	return ;
}

std::string	Brain::getIdea(int i) const
{
	return (this->ideas[i]);
}

std::string	*Brain::getAddress(int i)
{
	return (&this->ideas[i]);
}
