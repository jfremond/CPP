/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 18:58:44 by jfremond          #+#    #+#             */
/*   Updated: 2023/05/02 21:43:14 by jfremond         ###   ########.fr       */
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
	std::vector<int>	cpy(_unsorted);
	std::vector<int>::const_iterator	it;

	if (!arg.compare("After: "))
		std::sort(cpy.begin(), cpy.end());
	std::cout << arg;
	for (it = cpy.begin(); it != cpy.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void	PmergeMe::checkUnsortedVec()
{
	std::vector<int>	cpy(_unsorted);
	std::sort(cpy.begin(), cpy.end());
	std::vector<int>::const_iterator	it;
	std::vector<int>::const_iterator	prev;
	for (it = cpy.begin() + 1; it != cpy.end(); ++it)
	{
		prev = it - 1;
		if (*it == *prev)
			throw HasDuplicate();
	}
	if (_unsorted == cpy)
		throw AlreadySorted();
}

void PmergeMe::_recSortVec(std::vector<int>& vec, int size)
{
	int	last_elem;
	int	i;

	if (size <= 1)
		return ;
	_recSortVec(vec, size - 1);
	last_elem = vec[size - 1];
	i = size - 2;
	while (i >= 0 && vec[i] > last_elem)
	{
		vec[i + 1] = vec[i];
		i--;
	}
	vec[i + 1] = last_elem;
}

void PmergeMe::_recSortDeq(std::deque<int>& deq, int size)
{
	int	last_elem;
	int	i;

	if (size <= 1)
		return ;
	_recSortDeq(deq, size - 1);
	last_elem = deq[size - 1];
	i = size - 2;
	while (i >= 0 && deq[i] > last_elem)
	{
		deq[i + 1] = deq[i];
		i--;
	}
	deq[i + 1] = last_elem;
}

void	PmergeMe::_sortVec()
{
	std::vector<std::pair<int, int> >	tmp;
	for (size_t i = 0; i < _unsorted.size(); i += 2)
	{
		if (_unsorted.size() % 2 && i == _unsorted.size() - 1)
			_unsorted[i + 1] = -1;
		tmp.push_back(std::make_pair(_unsorted[i], _unsorted[i + 1]));
	}
	std::vector<std::pair<int, int> >::iterator	itt;
	for (itt = tmp.begin(); itt != tmp.end(); ++itt)
	{
		if (itt->second != -1)
		{
			if (itt->first > itt->second)
				std::swap(itt->first, itt->second);
			_vec.push_back(itt->second);
		}
	}
	_recSortVec(_vec, _vec.size());
	std::vector<std::pair<int, int> >::const_iterator	citt;
	for (citt = tmp.begin(); citt != tmp.end(); ++citt)
		_vec.insert(std::lower_bound(_vec.begin(), _vec.end(), citt->first), citt->first);
}

void	PmergeMe::_sortDeq()
{
	std::deque<std::pair<int, int> >	tmp;
	for (size_t i = 0; i < _unsorted.size(); i += 2)
	{
		if (_unsorted.size() % 2 && i == _unsorted.size() - 1)
			_unsorted[i + 1] = -1;
		tmp.push_back(std::make_pair(_unsorted[i], _unsorted[i + 1]));
	}	
	std::deque<std::pair<int, int> >::iterator	itt;
	for (itt = tmp.begin(); itt != tmp.end(); ++itt)
	{
		if (itt->second != -1)
		{
			if (itt->first > itt->second)
				std::swap(itt->first, itt->second);
			_deq.push_back(itt->second);
		}
	}
	_recSortDeq(_deq, _deq.size());
	std::deque<std::pair<int, int> >::const_iterator	citt;
	for (citt = tmp.begin(); citt != tmp.end(); ++citt)
		_deq.insert(std::lower_bound(_deq.begin(), _deq.end(), citt->first), citt->first);
}

void	PmergeMe::printTimeVec()
{
	clock_t begin = clock();
	_sortVec();
	clock_t end = clock();
	_vec_time = (end -  begin) * 1000000 / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _vec.size() << " with std::vector : " << _vec_time << " us" << std::endl;
}

void	PmergeMe::printTimeDeq()
{
	clock_t begin = clock();
	_sortDeq();
	clock_t end = clock();
	_deq_time = (end -  begin) * 1000000 / CLOCKS_PER_SEC;
	std::cout << "Time to process a range of " << _deq.size() << " with std::deque : " << _deq_time << " us" << std::endl;
}

std::vector<int>&	PmergeMe::getUnsortedVec()
{
	return (_unsorted);
}
