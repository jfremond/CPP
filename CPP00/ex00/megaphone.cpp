/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:45:44 by jfremond          #+#    #+#             */
/*   Updated: 2022/06/01 19:46:04 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void convert_to_uppercase(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
		str[i] = toupper(str[i]);
	std::cout << str;
}

int	main(int argc, char **argv)
{
	std::string no_arg = "* loud and unbeareable feedback noise *";
	if (argc == 1)
		convert_to_uppercase(no_arg);
	else
		for (int j = 1; j < argc; j++)
			convert_to_uppercase(argv[j]);
	std::cout << std::endl;
	return (0);
}