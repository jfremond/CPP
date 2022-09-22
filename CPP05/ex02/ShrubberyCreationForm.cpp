/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 05:27:28 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/22 16:17:17 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form(), _target(this->getName())
{
	std::cout << GREEN << "Default" << RESET << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form(target, 145, 137), _target(target) 
{
	std::cout << GREEN << "String" << RESET << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : Form(src)
{
	(*this) = src;
	std::cout << GREEN << "Copy" << RESET << std::endl;	
	return ;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	(void)rhs;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << "Destructor" << std::endl;
	return ;
}

void			ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() <= this->getGradeExec())
	{
		std::string		filename = this->_target;
		std::string		extension = "_shrubbery";
		filename.append(extension);
		std::ofstream	ofs(filename.c_str());
		if (!ofs.is_open())
		{
			std::cout << "Error when opening file" << std::endl;
			return ;
		}
	}
	else
		throw Form::GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &os, ShrubberyCreationForm const &obj)
{
	os << "Name : " << obj.getName() << std::endl;
	os << "Signed : " << obj.getSigned() << std::endl;
	os << "Grade to sign : " << obj.getGradeSign() << std::endl;
	os << "Grade to execute : " << obj.getGradeExec() << std::endl;
	return (os);
}
