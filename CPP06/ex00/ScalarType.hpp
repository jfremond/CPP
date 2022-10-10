/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarType.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 00:48:39 by jfremond          #+#    #+#             */
/*   Updated: 2022/10/10 04:09:40 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARTYPE_HPP
#define SCALARTYPE_HPP

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define ORANGE  "\033[38;2;255;165;0m"

#include <iostream>
#include <stdexcept>
#include <limits>
#include <cstdlib>

class ScalarType
{
	private:
		int			_value; // 1 char; 2 int; 3 float; 4 double
		ScalarType();
	public:
		ScalarType(ScalarType const &src);
		ScalarType	&operator=(ScalarType const &rhs);
		~ScalarType();
		
		//!	Determine type
		//!	Print char
		//!	Print int
		//!	Print float
		//!	Print double
		//!	Print all
};
		int	determineType(char *arg);

ScalarType::ScalarType()
{
	return ;
}

ScalarType::ScalarType(ScalarType const &src)
{
	(*this) = src;
	std::cout << GREEN << "" << RESET << std::endl;
}

ScalarType	&ScalarType::operator=(ScalarType const &rhs)
{
	this->_value = rhs._value;
	return (*this);
}

ScalarType::~ScalarType()
{
	std::cout << RED << "ScalarType destructor called" << RESET << std::endl;
	return ;
}

int	determineType(char *arg)
{	
	//	TODO Determine what type it is
	//	Return value
	//	Convert value to other types
	//	Print all
	double value = std::atof(arg);
	float test1 = static_cast<float>(value);
	std::cout << "float : " << test1 << ".0f" << std::endl;
	int	test2 = static_cast<int>(value);
	std::cout << "int : " << test2 << std::endl;
	char	test3 = static_cast<char>(value);
	std::cout << "char : " << test3 << std::endl;
	double	test4 = static_cast<double>(value);
	std::cout << "int : " << test4 << ".0" << std::endl;
	return 0;
}

#endif
