/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 05:00:08 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/22 00:38:38 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		std::string const	_name;
		bool				_signed;
		int const			_gradeSign;
		int const			_gradeExec;
	public:
		AForm();
		AForm(std::string const name, int const gts, int const gte);
		AForm(AForm const &src);
		AForm				&operator=(AForm const &rhs);
		~AForm();
		std::string const 	&getName() const;
		bool const			&getSigned() const;
		int const			&getGradeSign() const;
		int const			&getGradeExec() const;
		void				beSigned(Bureaucrat const &bc);
		virtual void		execute(Bureaucrat const &executor) const = 0;
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("One of the grades is too high, can't handle form");
				}
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw()
				{
					return ("One of the grades is too low, can't handle form");
				}
		};
};

std::ostream	&operator<<(std::ostream &os, AForm const &obj);

#endif
