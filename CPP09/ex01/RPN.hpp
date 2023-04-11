/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:17:27 by jfremond          #+#    #+#             */
/*   Updated: 2023/04/10 18:48:38 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <stdexcept>
#include <iostream>
#include <sstream>
#include <cctype>
#include <list>

class RPN
{
	private:
		std::list<int>	_lst;
		double			_stod(std::string const &to_cast);
		int				_isope(int const &ch);
	public:
		RPN();
		RPN(RPN const &src);
		RPN	&operator=(RPN const &rhs);
		~RPN();
		void			check_str(std::string const &str);
		void			do_ope(std::string const &str);
		void			print_res();
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
		class Emptylist : public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Error: list is empty");
				}
		};
		class NotEnoughValues : public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Error: not contain enough values to do an operation");
				}
		};
		class TooManyValues : public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Error: too many values in list");
				}
		};
};

#endif
