/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 17:27:09 by jfremond          #+#    #+#             */
/*   Updated: 2022/11/30 04:11:17 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _size(0)
{
	return ;
}

Span::Span(unsigned int N) : _size(N)
{
	return ;
}

Span::Span(Span const &src)
{
	(*this) = src;
	return ;
}

Span	&Span::operator=(Span const &rhs)
{
	_vec.clear();	
	_size = rhs._size;
	std::copy(rhs._vec.begin(), rhs._vec.end(), std::back_inserter(_vec));
	return (*this);
}

Span::~Span()
{
	_vec.clear();
	return ;
}

void	Span::addNumber(int i)
{
	if (_vec.size() == _size)
		throw Span::VecIsFullException();
	_vec.push_back(i);
}

int	Span::shortestSpan()
{
	if (_size < 2)
		throw Span::NotEnoughValuesException();
	std::vector<int>	tmp = _vec;
	std::sort(tmp.begin(), tmp.end());
	
	int	diff = tmp.at(1) - tmp.at(0);
	for (unsigned int i = 1; i < tmp.size() ; i++)
	{
		int	tmpdiff = tmp.at(i) - tmp.at(i - 1);
		if (tmpdiff < diff)
			diff = tmpdiff;
	}
	return (std::abs(diff));
}

int	Span::longuestSpan()
{
	if (_size < 2)
		throw Span::NotEnoughValuesException();
	std::vector<int>	tmp = _vec;
	std::sort(tmp.begin(), tmp.end());

	int	diff = *tmp.rbegin() - *tmp.begin();
	return (std::abs(diff));
}

void	Span::fillVec(std::vector<int>::const_iterator begin, std::vector<int>::const_iterator end)
{
	std::vector<int>::const_iterator it;
	for (it = begin; it != end; it++)
	{
		addNumber(*it);
		_size++;
	}
}

void	Span::printVec()
{
	std::vector<int>::const_iterator	it;
	int i = 1;
	for (it = _vec.begin(); it != _vec.end(); it++)
	{
		std::cout << YELLOW << "Value " << i << " : " << RESET << *it << std::endl;
		i++;
	}
	
}
