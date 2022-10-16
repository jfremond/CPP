/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 04:21:29 by jfremond          #+#    #+#             */
/*   Updated: 2022/10/16 04:28:29 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

int		identify(std::string arg)
{
	if (arg.length() == 1 && !isdigit(arg.at(0)))
		return (1);
	else if (arg.length() > 1 && !isdigit(arg.at(1)) && arg.at(1) != '.'
			&& arg != "-inf" && arg != "inf" && arg != "+inf" && arg != "nan"
			&& arg != "-inff" && arg != "inff" && arg != "+inff" && arg != "nanf")
		return (0);
	else if (arg.length() > 1
			&& (arg == "-inf" || arg == "inf" || arg == "+inf" || arg == "nan"))
		return (4);
	else if (arg.length() > 1
			&& (arg == "-inff" || arg == "inff" || arg == "+inff" || arg == "nanf"))
		return (3);
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

int	set_precision(std::string arg, int type)
{
	if (type == 2)
		return (1);
	int	precision;
	int dot = arg.find('.');
	if (dot == -1)
		return (arg.length());
	else
	{
		precision = arg.length() - dot - 1;
		if (arg.at(arg.length() - 1) == 'f')
			precision--;
	}
	return (precision);
}
