/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 06:10:58 by jfremond          #+#    #+#             */
/*   Updated: 2022/10/17 07:01:18 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convertor.hpp"

void	Convertor::convert_from_char(char val_char)
{
	_val_char = val_char;
	_val_int = static_cast<int>(_val_char);
	_val_float = static_cast<float>(_val_char);
	_val_double = static_cast<double>(_val_char);
}

void	Convertor::convert_from_int(int val_int)
{
	_val_int = val_int;
	_val_char = static_cast<char>(_val_int);
	if (val_int < -128 || val_int > 255)
		_impo_char = true;
	_val_float = static_cast<float>(_val_int);
	_val_double = static_cast<double>(_val_int);
}

void	Convertor::convert_from_float(float val_float)
{
	_val_float = val_float;
	_val_char = static_cast<char>(_val_float);
	if (_val_float < -128 || _val_float > 255)
		_impo_char = true;
	_val_int = static_cast<int>(_val_float);
	if (_val_float < std::numeric_limits<int>::min() || _val_float > std::numeric_limits<int>::max())
		_impo_int = true;
	_val_double = static_cast<double>(_val_float);
}

void	Convertor::convert_from_double(double val_double)
{
	_val_double = val_double;
	_val_char = static_cast<char>(_val_double);
	if (_val_double < -128 || _val_double > 255)
		_impo_char = true;
	_val_int = static_cast<int>(_val_double);
	if (_val_double < std::numeric_limits<int>::min() || _val_double > std::numeric_limits<int>::max())
		_impo_int = true;
	_val_float = static_cast<float>(_val_double);
}
