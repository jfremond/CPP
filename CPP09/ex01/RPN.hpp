/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 04:03:04 by jfremond          #+#    #+#             */
/*   Updated: 2023/03/24 01:43:37 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <cctype>	//isspace, isdigit
#include <stack>

class RPN
{
	private:
		RPN();
		int					_error;
		std::stack<int>		_stack;
		double				_stod(std::string str_to_cast);
		std::string			_dtos(double val_to_cast);
		int					_isope(int ch);
		void				_do_ope(std::string const ope);
	public:
		RPN(std::string const ope);
		RPN(RPN const &src);
		RPN	&operator=(RPN const &rhs);
		~RPN();
};

RPN::RPN() : _error(0)
{
	std::cout << "Default constructor" << std::endl;
}

RPN::RPN(std::string const ope) : _error(0)
{
	std::cout << "String constructor" << std::endl;
	_do_ope(ope);
}

RPN::RPN(RPN const &src) : _error(src._error), _stack(src._stack)
{
	std::cout << "Copy constructor" << std::endl;
}

RPN	&RPN::operator=(RPN const &rhs)
{
	std::cout << "Assignment operator overload" << std::endl;
	_error = rhs._error;
	_stack = rhs._stack;
	return (*this);
}

RPN::~RPN()
{
	std::cout << "Destructor" << std::endl;
}

double	RPN::_stod(std::string str_to_cast)
{
	std::stringstream	stream;
	double				res;

	stream << str_to_cast;
	stream >> res;
	
	if (stream.fail())
		_error = 1;
	return (res);
}

std::string	RPN::_dtos(double val_to_cast)
{
	std::stringstream	stream;
	std::string			res;

	stream << val_to_cast;
	stream >> res;
	
	if (stream.fail())
		_error = 1;
	return (res);
}

int	RPN::_isope(int ch)
{
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
		return (1);
	return (0);
}

void	RPN::_do_ope(std::string ope)
{
	for (size_t i = 0; i < ope.length(); i++)
	{
		//& Si caractere non autorise
		if (!isspace(ope[i]) && !isdigit(ope[i]) && !_isope(ope[i]))
			_error = 2;
		if (i != 0 && (isdigit(ope[i]) || _isope(ope[i])))
		{
			if (!isspace(ope[i - 1]))
				_error = 2;
		}
	}
	if (_error == 0)
	{
		for (size_t i = 0; i < ope.length(); i++)
		{
			if (isdigit(ope[i]))
			{
				_stack.push(_stod(&ope[i]));
			}
			else if (_isope(ope[i]))
			{
				if (_stack.size() >= 2)
				{
					int a = _stack.top();
					_stack.pop();
					int b = _stack.top();
					_stack.pop();
					int res;
					switch (ope[i])
					{
						case '+':
							res = b + a;
							break;
						case '-':
							res = b - a;
							break;
						case '*':
							res = b * a;
							break;
						case '/':
							if (a == 0)
								_error = 2;
							else
								res = b / a;
							break;
						default:
							_error = 2;
						break;
					}
					_stack.push(res);
				}
				else
					_error = 2;
			}
		}
	}

	// //!Print res
	if (_error != 0)
		std::cout << "Error" << std::endl;
	if (_error == 0)
	{
		std::cout << _stack.top() << std::endl;
	}
	if (_stack.size() == 0 && _error == 0)
	{
		std::cout << "Error: stack is empty" << std::endl;
		return ;
	}
}

#endif
