/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:44:49 by jfremond          #+#    #+#             */
/*   Updated: 2023/04/03 10:45:20 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

RPN::RPN(std::string const ope)
{
	try
	{
		_do_ope(ope);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return ;
	}
}

RPN::RPN(RPN const &src) : _stack(src._stack) {}

RPN	&RPN::operator=(RPN const &rhs)
{
	_stack = rhs._stack;
	return (*this);
}

RPN::~RPN() {}

double	RPN::_stod(std::string const &to_cast)
{
	std::stringstream	stream;
	double				res;

	stream << to_cast;
	stream >> res;
	
	if (stream.fail())
		throw ConversionHasFailed();
	return (res);
}

int	RPN::_isope(int const &ch)
{
	switch (ch)
	{
		case '+':
			return (1);
		case '-':
			return (1);
		case '/':
			return (1);
		case '*':
			return (1);
		default:
			return (0);
	}
}

void	RPN::_check_str(std::string const &str)
{
	std::string::const_iterator	it;
	std::string::const_iterator	prev;
	for (it = str.begin(); it != str.end(); ++it)
	{
		if (!isspace(*it) && !isdigit(*it) && !_isope(*it))
			throw InvalidCharacter();
		if (it != str.begin() && (isdigit(*it) || _isope(*it)))
		{
			prev = it - 1;
			if (!isspace(*prev))
				throw NotSeparatedBySpaces();
		}
	}
}

void	RPN::_do_ope(std::string const &str)
{
	try
	{
		_check_str(str);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
		return ;
	}
	std::string::const_iterator	it;
	for (it = str.begin(); it != str.end(); ++it)
	{
		if (isdigit(*it))
		{
			try
			{
				_stack.push(_stod(&(*it)));
			}
			catch(const std::exception& e)
			{
				std::cout << e.what() << std::endl;
			}
		}
		else if (_isope(*it))
		{
			if (_stack.size() >= 2)
			{
				int rhs = _stack.top();
				_stack.pop();
				int lhs = _stack.top();
				_stack.pop();
				switch (*it)
				{
					case '+':
						_stack.push(lhs + rhs);
						break;
					case '-':
						_stack.push(lhs - rhs);
						break;
					case '*':
						_stack.push(lhs * rhs);
						break;
					case '/':
						if (rhs == 0)
							throw DivisionByZero();
						else
							_stack.push(lhs / rhs);
						break;
				}
			}
			else
				throw NotEnoughValues();
		}
	}
	try
	{
		_print_res();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}
}

void	RPN::_print_res()
{
	if (_stack.empty())
	{
		throw StackIsEmpty();
		return ;
	}
	if (_stack.size() > 1)
	{
		throw MoreThanOneValue();
		return ;
	}
	std::cout << _stack.top() << std::endl;
}
