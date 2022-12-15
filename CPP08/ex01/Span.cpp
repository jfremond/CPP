/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 19:29:28 by jfremond          #+#    #+#             */
/*   Updated: 2022/12/14 19:29:32 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : _N(0)
{
	return ;
}

Span::Span(unsigned int N) : _N(N)
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
	_N = rhs._N;
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
	if (_vec.size() == _N)
		throw Span::VecIsFullException();
	_vec.push_back(i);
}

int	Span::shortestSpan()
{
	if (_vec.size() < 2)
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

int	Span::longestSpan()
{
	if (_vec.size() < 2)
		throw Span::NotEnoughValuesException();
	std::vector<int>	tmp = _vec;
	std::sort(tmp.begin(), tmp.end());
	std::vector<int>::iterator	min = std::min_element(tmp.begin(), tmp.end());
	std::vector<int>::iterator	max = std::max_element(tmp.begin(), tmp.end());
	return (std::abs(*max - *min));
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

void	Span::printVecInFile(std::string filename)
{
	std::ofstream	ofs(filename.c_str());
	if (!ofs.is_open())
	{
		std::cout << RED << "Error when opening file" << RESET << std::endl;
		return ;
	}
	std::vector<int>::const_iterator	it;
	for (it = _vec.begin(); it != _vec.end(); it++)
	{
		ofs << *it << std::endl;
	}
	ofs.close();
}
