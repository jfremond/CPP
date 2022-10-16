/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 04:27:32 by jfremond          #+#    #+#             */
/*   Updated: 2022/10/16 04:33:01 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// ^ print.cpp
void	print_char(double value, std::string arg);
void	print_int(double value, std::string arg);
void	print_float(double value, int precision);
void	print_double(double value, int precision);
int		print_impossible();

// ^ utils.cpp
int		identify(std::string arg);
int		set_precision(std::string arg, int type);
