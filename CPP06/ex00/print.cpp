/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 06:11:35 by jfremond          #+#    #+#             */
/*   Updated: 2022/10/17 07:20:07 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convertor.hpp"

void	Convertor::print_char(std::string arg)
{
	if (this->_impo_char || arg == "nan" || arg == "nanf")
		std::cout << ORANGE << "char: " << RESET << "impossible" << std::endl;
	else if (!isprint(_val_char))
		std::cout << ORANGE << "char: " << RESET << "non displayable" << std::endl;
	else
		std::cout << ORANGE << "char: " << RESET << "'" << _val_char << "'" << std::endl;
}

void	Convertor::print_int(std::string arg)
{
	if (this->_impo_int || arg == "nan" || arg == "nanf")
		std::cout << ORANGE << "int: " << RESET << "impossible" << std::endl;
	else
		std::cout << ORANGE << "int: " << RESET <<_val_int << std::endl;
}

void	Convertor::print_float()
{
	std::cout << ORANGE << "float: " << RESET << std::fixed << std::setprecision(1) << _val_float << "f" << std::endl;
}

void	Convertor::print_double()
{
	std::cout << ORANGE << "double: " << RESET << std::fixed << std::setprecision(1) << _val_double << std::endl;
}

int		Convertor::print_impossible()
{
	std::string values[4] = {"char: ", "int: ", "float: ", "double: "};
	for (int i = 0; i < 4; i++)
		std::cout << ORANGE << values[i] << RESET << "impossible" << std::endl;
	return (1);
}
