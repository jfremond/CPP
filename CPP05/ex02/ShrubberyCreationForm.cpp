/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 05:27:28 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/22 18:53:59 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form(), _target(this->getName())
{
	std::cout << GREEN << "ShrubberyCreationForm default constructor called" << RESET << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form(target, 145, 137), _target(target) 
{
	std::cout << GREEN << "ShrubberyCreationForm " << this->_target << " string constructor called " << RESET << std::endl;
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : Form(src)
{
	(*this) = src;
	std::cout << GREEN << "ShrubberyCreationForm copy constructor called" << RESET << std::endl;	
	return ;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	(void)rhs;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << RED << "ShrubberyCreationForm " << this->_target << " destructor called" << std::endl;
	return ;
}

void			ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
		throw Form::IsNotSignedException();
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
		else
		{
			ofs << "		,@@@@@@@," << std::endl;
			ofs << "	,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
			ofs << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\'88/8o" << std::endl;
			ofs << "  ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
			ofs << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
			ofs << "  %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
			ofs << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
			ofs << "       |o|        |.|         |o|" << std::endl;
			ofs << "   o   |.|        | |         |.|      o" << std::endl;
			ofs << "__\\|/_/ ._\\_  ___/ ._\\_______/._ \\____\\|/_" << std::endl;
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
