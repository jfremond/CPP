/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 04:36:18 by jfremond          #+#    #+#             */
/*   Updated: 2023/03/26 14:23:31 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <queue>

class PmergeMe
{
	private:
		std::vector<int>												_vec;
		std::multiset<int>												_mset;
		std::priority_queue<int, std::vector<int>, std::greater<int> >	_pqueue;
		int	_error;
	public:
		PmergeMe();
		~PmergeMe();
		double	_stod(std::string str_to_cast);
		void	printVec();
		std::vector<int>&	getVec();
		void	display1();
};

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

double	PmergeMe::_stod(std::string str_to_cast)
{
	std::stringstream	stream;
	double	res;
	
	stream << str_to_cast;
	stream >> res;
	if (stream.fail())
		_error = 1;
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

void	PmergeMe::display1()
{
	//! Determine the largest value out of the pairs
	std::vector<int> tab(_vec.size(), 0);
	for (size_t i = 0; i < _vec.size(); i++)
	{
		if (i % 2)
		{
			if (_vec[i] > _vec[i - 1])
			{
				tab[i] = 1;
				std::swap(_vec[i], _vec[i - 1]);
				std::swap(tab[i], tab[i - 1]);
			}
			else
				tab[i - 1] = 1;
		}
	}
	for (size_t i = 0; i < _vec.size(); i++)
	{
		std::cout << "value: " << _vec[i] << "\t" << "check: " << tab[i] << std::endl;
	}
	for (size_t i = 0; i < tab.size(); i++)
	{
		if (tab[i] == true)
		{
			_mset.insert(_vec[i]);
			_pqueue.push(_vec[i]);
		}
	}
	int	top = _pqueue.top();
	//! Find value associated with smallest value in sorted sequence
	for (size_t i = 0; i < _vec.size(); i++)
	{
		if (_vec[i] == top)
		{
			std::cout << "i: " << _vec[i] << std::endl;
			std::cout << "i + 1: " << _vec[i + 1] << std::endl;
			_pqueue.push(_vec[i + 1]);
			_mset.insert(_vec[i + 1]);
		}
	}
	top = _pqueue.top();
	for (size_t i = 0; i < _vec.size(); i++)
	{
		if (tab[i] == 0 && _vec[i] != top)
		{
			_mset.insert(_vec[i]);
			_pqueue.push(_vec[i]);
		}
	}
	
	std::multiset<int>::const_iterator	it;
	for (it = _mset.begin(); it != _mset.end(); it++)
	{
		std::cout << "mset: " << *it << std::endl;
	}
	while (!_pqueue.empty()) {
        int value = _pqueue.top();
        _pqueue.pop();
		std::cout << "pqueue: " << value << std::endl;
    }
}
#endif