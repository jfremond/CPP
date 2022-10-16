/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 02:13:30 by jfremond          #+#    #+#             */
/*   Updated: 2022/10/16 04:32:02 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << RED << "Usage: ./Convert [argument]" << RESET << std::endl;
		return (1);
	}
	std::string arg;
	int			type;
	double		value;
	int			precision;
	
	arg = argv[1];
	type = identify(arg);
	if (type == 0)
		return (print_impossible());
	else if (type == 1)
	{
		value = arg[0];
		precision = 1;
	}
	else
	{
		value = atof(arg.c_str());
		precision = set_precision(arg, type);
	}
	print_char(value, arg);
	print_int(value, arg);
	print_float(value, precision);
	print_double(value, precision);
	return (0);
}