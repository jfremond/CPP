/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 04:36:18 by jfremond          #+#    #+#             */
/*   Updated: 2023/04/06 18:00:11 by jfremond         ###   ########.fr       */
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


//& For the time
// #include <ctime>


//     clock_t begin = clock();
    
//     // Do something
//     // sleep( 2 );    // Wait 2 seconds, but no ticks are consumed
//     int i;
//     for( i=0; i<1000000000; i++ ) {
//     }
    
//     clock_t end = clock();
//     unsigned long millis = (end -  begin) * 1000 / CLOCKS_PER_SEC;        
//& For the time

class PmergeMe
{
	private:
		std::vector<int>	_vec;
		std::deque<int>		_deq;
	public:
		PmergeMe();
		~PmergeMe();
		std::vector<int>&	getVec();
		double				_stod(std::string const &to_cast);
		void				printVec();
		void				checkVec();
		void				display1();
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
