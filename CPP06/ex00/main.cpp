/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/08 00:59:22 by jfremond          #+#    #+#             */
/*   Updated: 2022/10/10 03:47:12 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarType.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << RED << "Usage: ./ScalarConversion [value]" << RESET << std::endl;
		return (1);
	}
	determineType(argv[1]);
	// ScalarType	value(argv[1]);
	return (0);
}