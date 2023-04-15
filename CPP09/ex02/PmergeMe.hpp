/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 04:36:18 by jfremond          #+#    #+#             */
/*   Updated: 2023/04/13 17:46:52 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <exception>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <deque>

class PmergeMe
{
	private:
		std::vector<int>	_unsorted;
		std::vector<int>	_vec;
		std::deque<int>		_deq;
		unsigned int		_vec_time;
		unsigned int		_deq_time;
		void				_recSortVec(std::vector<int>& vec, int size);
		void				_recSortDeq(std::deque<int>& deq, int size);
		void				_sortVec();
		void				_sortDeq();
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &src);
		PmergeMe	&operator=(PmergeMe const &rhs);
		~PmergeMe();
		double				myStod(std::string const &to_cast);
		void				printVec(std::string const &arg);
		void				checkUnsortedVec();
		void				printTimeVec();
		void				printTimeDeq();
		std::vector<int>&	getUnsortedVec();
		class WrongUsage : public std::exception 
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Error:\nUsage: ./PmergeMe \"sequence to sort\"");
				}
		};
		class ConversionFailed : public std::exception 
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Error: conversion has failed");
				}
		};
		class ForbiddenCharacters : public std::exception 
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Error: forbidden characters in string");
				}
		};
		class BiggerThanInt : public std::exception 
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Error: value is bigger than int");
				}
		};
		class AlreadySorted : public std::exception 
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Error: sequence is already sorted");
				}
		};
		class HasDuplicate : public std::exception 
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Error: sequence has a duplicate");
				}
		};
};

#endif
