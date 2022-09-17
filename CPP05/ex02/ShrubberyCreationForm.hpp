/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 23:45:23 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/17 04:49:28 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "Form.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		std::string				_target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const &target);
		ShrubberyCreationForm(ShrubberyCreationForm const &src);
		ShrubberyCreationForm	&operator=(ShrubberyCreationForm const &rhs);
		~ShrubberyCreationForm();
		virtual void			execute(Bureaucrat const &bc);
};

ShrubberyCreationForm::ShrubberyCreationForm() : AForm(), _target(this->getName())
{
	std::cout << GREEN << "ShrubberyCreationForm default constructor called" << RESET << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : AForm(target, this->getSignGrade(), this->getExecGrade()), _target(this->getName())
{
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src)
{
	return ;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << "ShrubberyCreationForm destructor called" << RESET << std::endl;
	return ;
}


void	ShrubberyCreationForm::execute(Bureaucrat const &bc)
{
	std::cout << bc.getName() << std::endl;
	// ! Check grades for Bureaucrat
	// ! Create file and check if open happened correctly
	// ? If all good write tree in file and close it
}

#endif
