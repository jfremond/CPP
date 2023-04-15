/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 02:32:06 by jfremond          #+#    #+#             */
/*   Updated: 2023/04/14 14:02:27 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() {}

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
		throw ConversionFailed();
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
		case '*':
			return (1);
		case '/':
			return (1);
		default:
			return (0);
	}
}

void	RPN::checkStr(std::string const &str)
{
	std::string::const_iterator	it;
	std::string::const_iterator	prev;
	for (it = str.begin(); it != str.end(); ++it)
	{
		if (!isspace(*it) && !isdigit(*it) && !_isope(*it))
			throw ForbiddenCharacters();
		if (it != str.begin() && (isdigit(*it) || _isope(*it)))
		{
			prev = it - 1;
			if (!isspace(*prev))
				throw NotSeparatedBySpace();
		}
	}
}

void	RPN::doOpe(std::string const &str)
{
	std::string::const_iterator	it;
	for (it = str.begin(); it != str.end(); ++it)
	{
		if (isdigit(*it))
			try
			{
				_stack.push(_stod(&(*it)));
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		if (_isope(*it))
		{
			if (_stack.size() >= 2)
			{
				int		rhs = _stack.top();
				_stack.pop();
				int		lhs = _stack.top();
				_stack.pop();
				double	res;
				switch (*it)
				{
					case '+':
						res = lhs + rhs;
						break;
					case '-':
						res = lhs - rhs;
						break;
					case '*':
						res = lhs * rhs;
						break;
					case '/':
						if (rhs == 0)
							throw DivisionByZero();
						else
							res = lhs / rhs;
						break;
				}
				if (res < std::numeric_limits<int>::min() || res > std::numeric_limits<int>::max())
					throw ExceedsIntLimits();
				else
					_stack.push(res);	
			}
			else
				throw NotEnoughValues();
		}
	}
}

void	RPN::printRes()
{
	if (_stack.empty())
		throw EmptyStack();
	else if (_stack.size() != 1)
		throw TooManyValues();
	std::cout << _stack.top() << std::endl;
}
