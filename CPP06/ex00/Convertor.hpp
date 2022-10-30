/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convertor.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 00:35:04 by jfremond          #+#    #+#             */
/*   Updated: 2022/10/17 07:11:02 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTOR_HPP
#define CONVERTOR_HPP

#include <iostream>
#include <cstdlib>	//atof
#include <limits>	//numeric_limits
#include <iomanip>	//precision

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define ORANGE  "\033[38;2;255;165;0m"

class Convertor
{
	private:
		char	_val_char;
		int		_val_int;
		float	_val_float;
		double	_val_double;
		bool	_impo_char;
		bool	_impo_int;
	public:
		Convertor();
		Convertor(Convertor const &src);
		Convertor	&operator=(Convertor const &rhs);
		~Convertor();
		int			identify(std::string arg);
		void		convert_from_char(char val_char);
		void		convert_from_int(int val_int);
		void		convert_from_float(float val_float);
		void		convert_from_double(double val_double);
		int			set_precision(std::string arg);
		void		print_char(std::string arg);
		void		print_int(std::string arg);
		void		print_float();
		void		print_double();
		int			print_impossible();
};

#endif
