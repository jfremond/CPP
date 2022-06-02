/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:17:59 by jfremond          #+#    #+#             */
/*   Updated: 2022/06/02 17:42:23 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string	*stringPTR = &str;
	std::string	&stringREF = str;

	std::cout << "Addresses :" << std::endl;
	std::cout << "str : " << &str << std::endl;
	std::cout << "PTR : " << stringPTR << std::endl;
	std::cout << "REF : " << &stringREF << std::endl << std::endl;

	std::cout << "Values :" << std::endl;
	std::cout << "str : " << str << std::endl;
	std::cout << "PTR : " << *stringPTR << std::endl;
	std::cout << "REF : " << stringREF << std::endl << std::endl;
	return (0);
}