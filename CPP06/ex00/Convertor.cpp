/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convertor.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 06:08:39 by jfremond          #+#    #+#             */
/*   Updated: 2022/10/17 07:12:32 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convertor.hpp"

Convertor::Convertor() : _val_char('\0'), _val_int(0), _val_float(0.0f), _val_double(0.0), _impo_char(false), _impo_int(false)
{
	return ;
}

Convertor::Convertor(Convertor const &src)
{
	(*this) = src;
	return ;
}

Convertor	&Convertor::operator=(Convertor const &rhs)
{
	_val_char = rhs._val_char;
	_val_int = rhs._val_int;
	_val_float = rhs._val_float;
	_val_double = rhs._val_double;
	_impo_char = rhs._impo_char;
	_impo_char = rhs._impo_int;
	return (*this);
}

Convertor::~Convertor()
{
	return ;
}

int		Convertor::identify(std::string arg)
{
	if (arg.length() == 1 && !isdigit(arg.at(0)))
		return (1);
	else if (arg.length() > 1 && !isdigit(arg.at(1)) && arg.at(1) != '.'
			&& arg != "-inf" && arg != "inf" && arg != "+inf" && arg != "nan"
			&& arg != "-inff" && arg != "inff" && arg != "+inff" && arg != "nanf")
		return (0);
	else if (arg.length() > 1 && (arg == "-inf" || arg == "inf" || arg == "+inf" || arg == "nan"))
		return (4);
	else if (arg.length() > 1 && (arg == "-inff" || arg == "inff" || arg == "+inff" || arg == "nanf"))
		return (3);
	else if (arg.length() > 1 && (atof(arg.c_str()) < std::numeric_limits<int>::min() || atof(arg.c_str()) > std::numeric_limits<int>::max()))
		return (4);
	else
	{
		int dot;
		int dot2;
		for (size_t i = 0; i < arg.length(); i++)
		{
			dot = arg.find_first_of('.');
			if (dot != -1)
			{
				dot2 = arg.find_last_of('.');
				if (dot2 != dot)
					return (0);
				if (arg.at(arg.length() - 1) == 'f')
					return (3);
				else
					return (4);
			}
			return (2);
		}
	}
	return (0);
}
