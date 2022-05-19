/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 15:45:44 by jfremond          #+#    #+#             */
/*   Updated: 2022/05/19 16:25:00 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

void upper(std::string str)
{
	for (std::basic_string<char>::size_type j = 0; j < str.length(); j++)
			str[j] = toupper(str[j]);
		std::cout << str;
}

int	main(int argc, char **argv)
{
	std::string no_arg = "* loud and unbereable feedback noise *";
	if (argc == 1)
	{
		upper(no_arg);
		std::cout << std::endl;
	}
	else
	{
		for (int i = 1; i < argc; i++)
			upper(argv[i]);
		std::cout << std::endl;
	}
	return (0);
}