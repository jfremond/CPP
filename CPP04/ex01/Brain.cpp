/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 22:08:02 by jfremond          #+#    #+#             */
/*   Updated: 2022/08/27 09:50:24 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	for (int i = 0; i < 100; i++)
		this->_ideas[i] = "A new idea...";
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
		this->_ideas[i] = rhs._ideas[i];
	return (*this);
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor called" << std::endl;
	return ;
}

std::string	Brain::getIdea(int index)
{
	if (index >= 100)
	{
		std::cout << "Index can't be greater than 100" << std::endl;
		return (std::string());
	}
	return (this->_ideas[index]);
}

void	Brain::setIdea(std::string str, int index)
{
	if (index >= 100)
	{
		std::cout << "Index can't be greater than 100" << std::endl;
		return ;
	}
	this->_ideas[index] = str;
}
