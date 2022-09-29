/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 22:56:08 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/29 17:01:13 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	std::cout << GREEN << "Intern default constructor called" << RESET << std::endl;
	return ;
}

Intern::Intern(Intern const &src)
{
	(*this) = src;
	std::cout << GREEN << "Intern copy constructor called" << RESET << std::endl;
	return ;
}

Intern	&Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return (*this);
}

Intern::~Intern()
{
	std::cout << RED << "Intern destructor called" << RESET << std::endl;
	return ;
}

Form	*Intern::makeForm(std::string const &name, std::string const &target)
{
	std::string	names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	int index = 0;
	while (index < 3)
	{
		if (name == names[index])
			break;
		index++;
	}
	switch (index)
	{
		case (0):
			std::cout << "Intern creates " << target << std::endl;
			return (new ShrubberyCreationForm(target));
			break;
		case (1):
			std::cout << "Intern creates " << target << std::endl;
			return (new RobotomyRequestForm(target));
			break;
		case (2):
			std::cout << "Intern creates " << target << std::endl;
			return (new PresidentialPardonForm(target));
			break;
		default:
			throw Intern::FormNotCreated();
	}
}
