/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:17:27 by jfremond          #+#    #+#             */
/*   Updated: 2023/04/14 14:06:32 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stdexcept>
#include <iostream>
#include <sstream>
#include <cctype>
#include <limits>
#include <stack>
#include <list>

class RPN
{
	private:
		std::stack<int, std::list<int> >	_stack;
		double								_stod(std::string const &to_cast);
		int									_isope(int const &ch);
	public:
		RPN();
		RPN(RPN const &src);
		RPN	&operator=(RPN const &rhs);
		~RPN();
		void								checkStr(std::string const &str);
		void								doOpe(std::string const &str);
		void								printRes();
		class WrongUsage : public std::exception 
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Error:\nUsage: ./RPN \"operation\"");
				}
		};
		class ConversionFailed : public std::exception 
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Error: conversion failed");
				}
		};
		class ForbiddenCharacters : public std::exception 
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Error: forbidden character in input string");
				}
		};
		class NotSeparatedBySpace : public std::exception 
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Error: characters not separated by space");
				}
		};
		class DivisionByZero : public std::exception 
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Error: division by zero");
				}
		};
		class EmptyStack : public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Error: stack is empty");
				}
		};
		class NotEnoughValues : public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Error: not enough values to do an operation");
				}
		};
		class TooManyValues : public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Error: too many values in stack");
				}
		};
		class ExceedsIntLimits : public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Error: result exceeds integer limits");
				}
		};
};

#endif
