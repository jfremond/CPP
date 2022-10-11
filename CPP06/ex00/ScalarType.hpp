/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarType.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 00:48:39 by jfremond          #+#    #+#             */
/*   Updated: 2022/10/11 15:38:17 by jfremond         ###   ########.fr       */
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
#include <cstdlib>	// atof
#include <cstring>	// strlen
#include <limits>	// numeric_limits
#include <stdexcept>

class ScalarType
{
	private:
		int			_value; // 1 char; 2 int; 3 double; 4 float
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
int		determineType(char *arg);
void	print_char(char *arg);

struct InvalidNumberOfArgsException : public std::exception
{
	const char *what() const throw()
	{
		return ("Usage: ./ScalarConversion [value]");
	}
};

struct InvalidArgumentException : public std::exception
{
	const char *what() const throw()
	{
		return ("Invalid argument entered");
	}		
};


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
	std::cout << "max numeric limits int : "<< std::numeric_limits<int>::max()<< std::endl;
	std::cout << "min numeric limits int : "<< std::numeric_limits<int>::min()<< std::endl;
	std::cout << "max numeric limits double : "<< std::numeric_limits<double>::max()<< std::endl;
	std::cout << "min numeric limits double : "<< std::numeric_limits<double>::min()<< std::endl;
	std::cout << "max numeric limits float : "<< std::numeric_limits<float>::max()<< std::endl;
	std::cout << "min numeric limits float : "<< std::numeric_limits<float>::min()<< std::endl;
	int res = 0;
	int dot = 0;
	if (std::strlen(arg) == 1)
	{
		if (std::isalpha(arg[0]))
			res = 1; // It is a char
		else if (std::isdigit(arg[0]))
			res = 2; // It is an int
		else
			res = -1; // You entered something that is not a number
		std::cout << res << std::endl;
		return (res);
	}
	else
	{
		if (!std::isdigit(arg[0]) && !std::isdigit(arg[1]))
		{			
			// INF PART
			if (!strcmp(arg, "inf") || !strcmp(arg, "+inf") || !strcmp(arg, "-inf") || !strcmp(arg, "nan"))
			{
				res = 3;
				std::cout << 3 << std::endl;
				return (res);
			}
			if (!strcmp(arg, "inff") || !strcmp(arg, "+inff") || !strcmp(arg, "-inff") || !strcmp(arg, "nanf"))
			{
				res = 4;
				std::cout << 4 << std::endl;
				return (res);
			}
			else
				return (-1);
		}
		res = 2;
		for (size_t i = 0; i < std::strlen(arg); i++)
		{
			if (arg[i] == '.')
			{
				if (dot == 1)
					return (-1); // You entered something that is not a number
				else
				{
					res = 3;
					dot = 1;
				}
			}
		}
		if (res == 3 and arg[std::strlen(arg) - 1] == 'f')
			res = 4;
	}
	// Check if double or float
	double value = atof(arg);
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
		res = 4;
	if ((value > 0 && value < std::numeric_limits<float>::min()) || value > std::numeric_limits<float>::max())
		res = 3;
	// Check if string has digit
	// Check if more than one operator +/-
	// float value = std::atof(arg);
	// std::cout << "value : " << value << std::endl;
	// float test1 = static_cast<float>(value);
	// std::cout << "float : " << test1 << ".0f" << std::endl;
	// int	test2 = static_cast<int>(value);
	// std::cout << "int : " << test2 << std::endl;
	// char	test3 = static_cast<char>(value);
	// std::cout << "char : " << test3 << std::endl;
	// double	test4 = static_cast<double>(value);
	// std::cout << "double : " << test4 << ".0" << std::endl;
	return (res);
}

void	print_char(char *arg)
{
	double value = arg[0];
	char c = static_cast<char>(value);
	if (!isprint(c))
		std::cout << "char: Non displayable" << std::endl;
	else
		std::cout << "char: '" << c << "'" << std::endl;
}

#endif
