/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 13:59:26 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/16 04:44:09 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool				_signed;
		int const			_signGrade;
		int const			_signExec;
	public:
		AForm();
		AForm(std::string const name, int const gts, int const gte);
		AForm(AForm const &src);
		AForm				&operator=(AForm const &rhs);
		~AForm();
		std::string const	&getName() const;
		bool const			&getSigned() const;
		int const			&getExecGrade() const;
		int const			&getSignGrade() const;
		void				checkGrades() const;
		virtual void		beSigned(Bureaucrat const &bc) = 0;
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

std::ostream	&operator<<(std::ostream &os, AForm const &obj);

#endif
