/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:58:44 by jfremond          #+#    #+#             */
/*   Updated: 2023/04/06 19:21:15 by jfremond         ###   ########.fr       */
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
	std::vector<int>	cpy(_vec);
	std::vector<int>::const_iterator	it;

	if (_vec.empty())
	{
		std::cout << "empty" << std::endl;
		return ;
	}
	std::cout << "Before: ";
	for (it = _vec.begin(); it != _vec.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
	std::sort(cpy.begin(), cpy.end());
	std::cout << "Sorted: ";
	for (it = cpy.begin(); it != cpy.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::checkVec()
{
	std::vector<int>	cpy(_vec);
	std::sort(cpy.begin(), cpy.end());
	std::vector<int>::const_iterator	it;
	std::vector<int>::const_iterator	prev;
	for (it = cpy.begin() + 1; it != cpy.end(); ++it)
	{
		prev = it - 1;
		if (*it == *prev)
			throw HasDuplicate();
	}
	if (_vec == cpy)
		throw AlreadySorted();
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
	//& Create new vector
	std::vector<std::pair<int, int> >	tab;
	//& Push pairs in vector
	for (size_t i = 0; i < _vec.size(); i += 2)
		tab.push_back(std::make_pair(_vec[i], _vec[i + 1]));
	//& Clear final vector
	_vec.clear();
	//& Display new vector with pairs
	std::vector<std::pair<int, int> >::const_iterator	citt;
	for (citt = tab.begin(); citt != tab.end(); ++citt)
	{	
		if (citt->second)
			std::cout << "first: " << citt->first << " second: " << citt->second << std::endl;
		else
			std::cout << "first: " << citt->first << std::endl;
	}
	//& Sort pairs
	std::vector<std::pair<int, int> >::iterator	itt;
	for (itt = tab.begin(); itt != tab.end(); ++itt)
	{
		if (itt->second)
		{
			if (itt->first > itt->second)
				std::swap(itt->first, itt->second);
		}
	}
	//& Display vector to make sure pairs are sorted
	for (citt = tab.begin(); citt != tab.end(); ++citt)
	{		
		if (citt->second)
			std::cout << "first: " << citt->first << " second: " << citt->second << std::endl;
		else
			std::cout << "first: " << citt->first << std::endl;
	}
	//& Push larger values in sorted sequence (you push then sort)
	std::vector<int>::reverse_iterator	itvr;
	std::vector<int>::reverse_iterator	itvr_prev;
	for (citt = tab.begin(); citt != tab.end(); ++citt)
	{		
		if (citt->second)
		{
			_vec.push_back(citt->second);
			for (itvr = _vec.rbegin(); itvr != _vec.rend(); ++itvr)
			{
				itvr_prev = itvr + 1;
				if (*itvr < *itvr_prev)
					std::swap(*itvr, *itvr_prev);
			}
		}
	}
	//& Sort values associated with each values in sorted sequence (maybe special case if one pair with one value)
	for (citt = tab.begin(); citt != tab.end(); ++citt)
	{		
		_vec.insert(std::lower_bound(_vec.begin(), _vec.end(), citt->first), citt->first);
	}
}

	//! This works
	// //! Change tab to std::vector<std::pair<int, bool>>	tab;
	// std::vector<std::pair<int, bool> >	tab;
	// std::vector<int>::iterator	itv;
	// std::vector<int>::iterator	itv_prev;
	// std::vector<std::pair<int, bool> >::iterator	itt;
	// std::vector<std::pair<int, bool> >::iterator	itt_prev;
	// int	dist;
	// //! Fill tab with _vec values and false
	// for (itv = _vec.begin(); itv != _vec.end(); ++itv)
	// 	tab.push_back(std::pair<int, bool>(*itv, false));
	// //! Clear _vec	
	// _vec.clear();
	// //! Determine the largest value out of the pairs and sort them inside tab
	// for (itt = tab.begin(); itt != tab.end(); ++itt)
	// {
	// 	dist = std::distance(tab.begin(), itt);
	// 	if (dist % 2)
	// 	{
	// 		itt_prev = itt - 1;
	// 		if (itt->first < itt_prev->first)
	// 			std::swap(itt->first, itt_prev->first);
	// 		itt->second = true;
	// 	}
	// }
	// std::vector<std::pair<int, bool> >::iterator	itt2;
	// for (itt2 = tab.begin(); itt2 != tab.end(); ++itt2)
	// 	std::cout << "value: " << itt2->first << "\t" << itt2->second << std::endl;
	// //! Insert largest elements of the pairs in _vec
	// std::vector<std::pair<int, bool> >::const_iterator	citt;
	// std::vector<int>::reverse_iterator	itvr;
	// std::vector<int>::reverse_iterator	itvr_prev;
	// for (citt = tab.begin(); citt != tab.end(); ++citt)
	// {
	// 	if (citt->second == true)
	// 	{
	// 		_vec.push_back(citt->first);
	// 		//! Sort after insertion
	// 		for (itvr = _vec.rbegin(); itvr != _vec.rend(); ++itvr)
	// 		{
	// 			itvr_prev = itvr + 1;
	// 			if (*itvr < *itvr_prev)
	// 				std::swap(*itvr, *itvr_prev);
	// 		}
	// 	}
	// }
	// std::cout << "DISPLAY _VEC" << std::endl;
	// for (itv = _vec.begin(); itv !=_vec.end(); itv++)
	// {
	// 	std::cout << *itv << '\t';
	// }
	// std::cout << std::endl;
	
	// //! Find smallest number in _vec
	// std::vector<int>::iterator	small;
	// small =_vec.begin();
	// //! Insert the rest
	// dist = 0;
	// for (itt = tab.begin(); itt != tab.end(); ++itt)
	// {
	// 	dist = std::distance(tab.begin(), itt);
	// 	if ((dist % 2))
	// 	{
	// 		itt_prev = itt - 1;
	// 		if (itt->first == *small)
	// 		{
	// 			_vec.insert(std::lower_bound(_vec.begin(), _vec.end(), itt_prev->first), itt_prev->first);
	// 			itt = tab.begin();
	// 			small += 2;
	// 		}
	// 	}
	// 	else
	// 	{
	// 		if (itt == tab.end() - 1)
	// 			_vec.insert(std::lower_bound(_vec.begin(), _vec.end(), itt->first), itt->first);
	// 	}
	// }
	// std::cout << std::endl;
