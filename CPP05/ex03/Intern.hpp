/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 23:58:29 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/26 22:56:04 by jfremond         ###   ########.fr       */
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

#endif
