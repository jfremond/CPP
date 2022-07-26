/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 06:06:23 by jfremond          #+#    #+#             */
/*   Updated: 2022/07/22 06:06:24 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int	main(int argc, char **argv)
{
	Harl	harl;
	
	if (argc != 2)
	{
		std::cout << "Usage: ./Harl2.0 [level]" << std::endl;
		return (1);
	}
	harl.complain(argv[1]);
	return (0);
}