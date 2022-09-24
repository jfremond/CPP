/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 23:58:29 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/25 00:42:18 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
	public:
		Intern();
		Intern(Intern const &src);
		Intern	&operator=(Intern const &rhs);
		~Intern();
		Form	*makeForm(std::string const &name, std::string const &target);
		class FormNotCreated : public std::exception
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("Form was not created");
				}
		};
};

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
	int index = -1;
	while (index++ < 3)
		if (name == names[index])
			break;
	switch (index)
	{
		case (0):
			std::cout << CYAN << "Intern creates " << target << RESET << std::endl;
			return (new ShrubberyCreationForm(target));
			break;
		case (1):
			std::cout << CYAN << "Intern creates " << target << RESET << std::endl;
			return (new RobotomyRequestForm(target));
			break;
		case (2):
			std::cout << CYAN << "Intern creates " << target << RESET << std::endl;
			return (new PresidentialPardonForm(target));
			break;
		default:
			throw Intern::FormNotCreated();
			break;
	}
}

#endif
