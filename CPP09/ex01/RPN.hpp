/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 19:00:10 by jfremond          #+#    #+#             */
/*   Updated: 2023/04/03 10:45:11 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stdexcept>
#include <iostream>
#include <sstream>
#include <cctype>
#include <stack>

class RPN
{
	private:
		std::stack<int>		_stack;
		double				_stod(std::string const &to_cast);
		int					_isope(int const &ch);
		void				_check_str(std::string const &str);
		void				_do_ope(std::string const &str);
		void				_print_res();
		RPN();
	public:
		RPN(std::string const ope);
		RPN(RPN const &src);
		RPN	&operator=(RPN const &rhs);
		~RPN();
		class ConversionHasFailed : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Error: conversion has failed");
				}
		};
		class InvalidCharacter : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Error: invalid character in string");
				}
		};
		class NotSeparatedBySpaces : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Error: characters not separated by spaces");
				}
		};
		class NotEnoughValues : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Error: not enough values in stack");
				}
		};
		class DivisionByZero : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Error: division by zero");
				}
		};
		class StackIsEmpty : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Error: stack is empty");
				}
		};
		class MoreThanOneValue : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Error: more than one value in stack");
				}
		};
};

#endif
