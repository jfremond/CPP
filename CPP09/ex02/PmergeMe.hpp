/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 04:36:18 by jfremond          #+#    #+#             */
/*   Updated: 2023/04/11 06:53:36 by jfremond         ###   ########.fr       */
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
		std::vector<int>	_vec;
		std::deque<int>		_deq;
		unsigned int		_vec_time;
		unsigned int		_deq_time;
	public:
		PmergeMe();
		PmergeMe(PmergeMe const &src);
		PmergeMe	&operator=(PmergeMe const &rhs);
		~PmergeMe();
		double				myStod(std::string const &to_cast);
		void				printVec(std::string const &arg);
		void				printDeq(std::string const &arg);
		void				checkVec();
		void				recSortVec(std::vector<int>& vec, int n);
		void				recSortDeq(std::deque<int>& deq, int n);
		void				sortVec();
		void				sortDeq();
		void				printTimeVec();
		void				printTimeDeq();
		std::vector<int>&	getVec();
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
