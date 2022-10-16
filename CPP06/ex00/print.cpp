/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 04:16:00 by jfremond          #+#    #+#             */
/*   Updated: 2022/10/16 04:47:08 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

void	print_char(double value, std::string arg)
{
	if (value < 0 || value > 255 || arg == "nan" || arg == "nanf")
		std::cout << ORANGE << "char: " << RESET << "impossible" << std::endl;
	else
	{
		char c = static_cast<char>(value);
		if (!isprint(c))
			std::cout << ORANGE << "char: " << RESET << "non displayable" << std::endl;
		else
			std::cout << ORANGE << "char: " << RESET << "'" << c << "'" << std::endl;
	}

}

void	print_int(double value, std::string arg)
{
	if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max()
		|| arg == "nan" || arg == "nanf")
				std::cout << ORANGE << "int: " << RESET << "impossible" << std::endl;
	else
	{
		int num = static_cast<int>(value);
		std::cout << ORANGE << "int: " << RESET << num << std::endl;
	}
}

void	print_float(double value, int precision)
{
	double	fnum = static_cast<float>(value);
	std::cout << ORANGE << "float: " << std::fixed << std::setprecision(precision) << RESET << fnum << "f" << std::endl;
}

void	print_double(double value, int precision)
{
	double	dnum = static_cast<double>(value);
	std::cout << ORANGE << "double: " << std::fixed << std::setprecision(precision) << RESET << dnum << std::endl;
}

int	print_impossible(void)
{
	std::string	values[4] = {"char: ", "int: ", "float: ", "double: "};
	for (int i = 0; i < 4; i++)
		std::cout << ORANGE << values[i] << RESET << "impossible" << std::endl;
	return (1);
}
