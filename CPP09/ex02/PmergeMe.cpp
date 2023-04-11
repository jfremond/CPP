/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:58:44 by jfremond          #+#    #+#             */
/*   Updated: 2023/04/11 06:55:41 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(PmergeMe const &src) : _vec(src._vec), _deq(src._deq), _vec_time(src._vec_time), _deq_time(src._deq_time) {}

PmergeMe	&PmergeMe::operator=(PmergeMe const &rhs)
{
	_vec = rhs._vec;
	_deq = rhs._deq;
	_vec_time = rhs._vec_time;
	_deq_time = rhs._deq_time;
	return (*this);
}

PmergeMe::~PmergeMe() {}

double	PmergeMe::myStod(std::string const &to_cast)
{
	std::stringstream	stream;
	double	res;

	stream << to_cast;
	stream >> res;
	if (stream.fail())
		throw ConversionFailed();
	return (res);
}

void	PmergeMe::printVec(std::string const &arg)
{
	std::vector<int>	cpy(_vec);
	std::vector<int>::const_iterator	it;

	if (!arg.compare("After: "))
		std::sort(cpy.begin(), cpy.end());
	std::cout << arg;
	for (it = cpy.begin(); it != cpy.end(); it++)
	{
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::printDeq(std::string const &arg)
{
	std::deque<int>	cpy(_deq);
	std::deque<int>::const_iterator	it;

	std::cout << arg;
	for (it = _deq.begin(); it != _deq.end(); it++)
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

void PmergeMe::recSortVec(std::vector<int>& vec, int n)
{
	// Base case
	if (n <= 1)
		return;

	// Sort first n-1 elements
	recSortVec(vec, n - 1);
	
	// Insert last element in correct position
	int last = vec[n - 1];
	int j = n - 2;
	while (j >= 0 && vec[j] > last) {
		vec[j + 1] = vec[j];
		j--;
	}
	vec[j + 1] = last;
}

void PmergeMe::recSortDeq(std::deque<int>& deq, int n)
{
	// Base case
	if (n <= 1)
		return;

	// Sort first n-1 elements
	recSortDeq(deq, n - 1);
	
	// Insert last element in correct position
	int last = deq[n-1];
	int j = n - 2;
	while (j >= 0 && deq[j] > last) {
		deq[j + 1] = deq[j];
		j--;
	}
	deq[j + 1] = last;
}

void	PmergeMe::sortVec()
{
	std::vector<std::pair<int, int> >	tmp;
	for (size_t i = 0; i < _vec.size(); i += 2)
		tmp.push_back(std::make_pair(_vec[i], _vec[i + 1]));
	_vec.clear();
	std::vector<std::pair<int, int> >::iterator	itt;
	for (itt = tmp.begin(); itt != tmp.end(); ++itt)
	{
		if (itt->second)
		{
			if (itt->first > itt->second)
				std::swap(itt->first, itt->second);
			_vec.push_back(itt->second);
		}
	}
	recSortVec(_vec, _vec.size());
	std::vector<std::pair<int, int> >::const_iterator	citt;
	for (citt = tmp.begin(); citt != tmp.end(); ++citt)
		_vec.insert(std::lower_bound(_vec.begin(), _vec.end(), citt->first), citt->first);
}

void	PmergeMe::sortDeq()
{
	std::deque<std::pair<int, int> >	tmp;
	for (size_t i = 0; i < _vec.size(); i += 2)
		tmp.push_back(std::make_pair(_vec[i], _vec[i + 1]));
	std::deque<std::pair<int, int> >::iterator	itt;
	for (itt = tmp.begin(); itt != tmp.end(); ++itt)
	{
		if (itt->second)
		{
			if (itt->first > itt->second)
				std::swap(itt->first, itt->second);
			_deq.push_back(itt->second);
		}
	}
	recSortDeq(_deq, _deq.size());
	std::deque<std::pair<int, int> >::const_iterator	citt;
	for (citt = tmp.begin(); citt != tmp.end(); ++citt)
		_deq.insert(std::lower_bound(_deq.begin(), _deq.end(), citt->first), citt->first);
}

void	PmergeMe::printTimeVec()
{
	clock_t begin = clock();
	sortVec();
	clock_t end = clock();
	_vec_time = (end -  begin) * 1000000 / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _vec.size() << " with std::vector : " << _vec_time << " us" << std::endl;
}

void	PmergeMe::printTimeDeq()
{
	clock_t begin = clock();
	sortDeq();
	clock_t end = clock();
	_deq_time = (end -  begin) * 1000000 / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _deq.size() << " with std::deque : " << _deq_time << " us" << std::endl;
}

std::vector<int>&	PmergeMe::getVec()
{
	return (_vec);
}
