/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:58:44 by jfremond          #+#    #+#             */
/*   Updated: 2023/04/03 22:48:00 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

double	PmergeMe::_stod(std::string const &to_cast)
{
	std::stringstream	stream;
	double	res;
	
	stream << to_cast;
	stream >> res;
	if (stream.fail())
		throw ConversionFailed();
	return (res);
}

std::vector<int>&	PmergeMe::getVec()
{
	return (_vec);
}

void	PmergeMe::printVec()
{
	std::vector<int>::const_iterator	it;

	std::cout << "Before: ";
	for (it = _vec.begin(); it != _vec.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::checkVec()
{
	std::vector<int>	cpy(_vec);
	std::sort(cpy.begin(), cpy.end());
	if (_vec == cpy)
		throw AlreadySorted();
	std::vector<int>::const_iterator	it;
	std::vector<int>::const_iterator	prev;
	for (it = cpy.begin() + 1; it != cpy.end(); ++it)
	{
		prev = it - 1;
		if (*it == *prev)
			throw HasDuplicate();
	}
}

void	PmergeMe::display1()
{
	try
	{
		checkVec();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return ;
	}
	//! Put pairs in minivectors
	// //! Determine the largest value out of the pairs
	// std::vector<int> tab(_vec.size(), 0);
	// for (size_t i = 0; i < _vec.size(); i++)
	// {
	// 	if (i % 2)
	// 	{
	// 		if (_vec[i] > _vec[i - 1])
	// 		{
	// 			tab[i] = 1;
	// 			std::swap(_vec[i], _vec[i - 1]);
	// 			std::swap(tab[i], tab[i - 1]);
	// 		}
	// 		else
	// 			tab[i - 1] = 1;
	// 	}
	// }
	// for (size_t i = 0; i < _vec.size(); i++)
	// {
	// 	std::cout << "value: " << _vec[i] << "\t" << "check: " << tab[i] << std::endl;
	// }
	// for (size_t i = 0; i < tab.size(); i++)
	// {
	// 	if (tab[i] == true)
	// 	{
	// 		_mset.insert(_vec[i]);
	// 		_pqueue.push(_vec[i]);
	// 	}
	// }
	// int	top = _pqueue.top();
	// //! Find value associated with smallest value in sorted sequence
	// for (size_t i = 0; i < _vec.size(); i++)
	// {
	// 	if (_vec[i] == top)
	// 	{
	// 		std::cout << "i: " << _vec[i] << std::endl;
	// 		std::cout << "i + 1: " << _vec[i + 1] << std::endl;
	// 		_pqueue.push(_vec[i + 1]);
	// 		_mset.insert(_vec[i + 1]);
	// 	}
	// }
	// top = _pqueue.top();
	// for (size_t i = 0; i < _vec.size(); i++)
	// {
	// 	if (tab[i] == 0 && _vec[i] != top)
	// 	{
	// 		_mset.insert(_vec[i]);
	// 		_pqueue.push(_vec[i]);
	// 	}
	// }
	
	// std::multiset<int>::const_iterator	it;
	// for (it = _mset.begin(); it != _mset.end(); it++)
	// {
	// 	std::cout << "mset: " << *it << std::endl;
	// }
	// while (!_pqueue.empty()) {
    //     int value = _pqueue.top();
    //     _pqueue.pop();
	// 	std::cout << "pqueue: " << value << std::endl;
    // }
}
