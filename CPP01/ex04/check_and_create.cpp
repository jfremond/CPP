/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_create.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/05 21:23:55 by jfremond          #+#    #+#             */
/*   Updated: 2022/06/05 21:49:47 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replace.hpp"

int	check_args(int argc)
{
	if (argc != 4)
	{
		std::cout << "Usage : ./replace [filename] [s1] [s2]" << std::endl;
		return (1);
	}
	return (0);
}

int	check_strings(std::string s1, std::string s2)
{
	if (s1.length() == 0 || s2.length() == 0)
	{
		std::cout << "At least one of the strings is empty" << std::endl;
		return (1);
	}
	return (0);
}

std::string	create_oufile(char *arg)
{
	std::string	outfile;
	std::string	extension;
	
	extension = ".replace";
	outfile = arg + extension;
	return (outfile);
}

int	check_infile(std::ifstream &ifs, char *arg)
{
	struct stat	s;
	if (!stat(arg, &s) && s.st_mode & S_IFDIR)
	{
		std::cout << "Infile is a directory" << std::endl;
		return (1);
	}
	if (!ifs.is_open())
	{
		std::cout << "Infile couldn't open" << std::endl;
		return (1);
	}
	return (0);
}

int	check_outfile(std::ofstream &ofs)
{
	if (!ofs.is_open())
	{
		std::cout << "Outfile couldn't open" << std::endl;
		return (1);
	}
	return (0);
}