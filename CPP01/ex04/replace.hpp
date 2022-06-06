/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:31:24 by jfremond          #+#    #+#             */
/*   Updated: 2022/06/06 10:05:41 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACE_HPP
#define REPLACE_HPP

#include <iostream>
#include <fstream>
#include <sys/stat.h>

int			check_args(int argc);
int			check_strings(std::string s1, std::string s2);
int			check_infile(std::ifstream &ifs, std::string arg);
int			check_outfile(std::ofstream &ofs);
std::string	create_oufile(std::string arg);

#endif