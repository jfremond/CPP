/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:59:26 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/06 01:42:38 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool				_signed;
		int const			_signGrade;
		int const			_signExec;
	public:
		Form();
		Form(std::string const name, int const gts, int const gte);
		Form(Form const &src);
		Form				&operator=(Form const &rhs);
		~Form();
		std::string const	&getName() const;
		bool const			&getSigned() const;
		int const			&getExecGrade() const;
		int const			&getSignGrade() const;
		void				checkGrades() const;
		void				beSigned(Bureaucrat const &bc);
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Grade too high, can't handle form");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("Grade too low, can't handle form");
				}
		};
};

std::ostream	&operator<<(std::ostream &os, Form const &obj);

#endif
