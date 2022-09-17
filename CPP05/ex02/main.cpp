/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 15:23:29 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/17 04:44:32 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	std::cout << "Starting ex02" << std::endl;
	ShrubberyCreationForm	test;
	Bureaucrat	lala("lala", 10);
	test.beSigned(lala);
	test.execute(lala);
}