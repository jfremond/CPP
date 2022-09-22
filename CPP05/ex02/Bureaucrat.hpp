/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 00:46:32 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/22 05:13:28 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define ORANGE  "\033[38;2;255;165;0m"

#include <iostream>
#include <stdexcept>

#include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		std::string const	_name;
		int					_grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string const name, int grade);
		Bureaucrat(Bureaucrat const &src);
		Bureaucrat			&operator=(Bureaucrat const &rhs);
		~Bureaucrat();
		std::string const	&getName() const;
		int	const			&getGrade() const;
		void				incrementGrade();
		void				decrementGrade();
		void				checkGrade();
		void				signForm(AForm &form);
		void				executeForm(AForm const &form);
		class GradeTooHighException : public std::exception 
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("The grade of the bureaucrat is too high");
				}
		};
		class GradeTooLowException : public std::exception 
		{
			public:
				virtual const char	*what() const throw()
				{
					return ("The grade of the bureaucrat is too low");
				}
		};
};

std::ostream 	&operator<<(std::ostream &os, Bureaucrat const &obj);

#endif
