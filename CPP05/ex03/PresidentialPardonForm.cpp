/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:18:49 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/26 20:14:01 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form()
{
	std::cout << GREEN << "PresidentialPardonForm default constructor called" << RESET << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(std::string const target) : Form(target, 25, 5), _target(this->getName())
{
	std::cout << GREEN << "PresidentialPardonForm " << this->_target  << " string constructor called" << RESET << std::endl;
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) : Form(src), _target(src._target)
{
	(*this) = src;
	std::cout << GREEN << "PresidentialPardonForm copy constructor called" << RESET << std::endl;
	return ;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs)
{
	(void)rhs;
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << RED << "PresidentialPardonForm " << this->_target << " destructor called" << RESET << std::endl;
	return ;
}

void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
		throw Form::IsNotSignedException();
	else if (executor.getGrade() > this->getGradeExec())
		throw Form::GradeTooLowException();
	else
		std::cout << CYAN << this->_target << " has been pardoned by Zaphod Beeblebox." << RESET << std::endl;
}

std::ostream	&operator<<(std::ostream &os, PresidentialPardonForm const &obj)
{
	os << "Name : " << obj.getName() << std::endl;
	os << "Signed : " << obj.getSigned() << std::endl;
	os << "Grade to sign : " << obj.getGradeSign() << std::endl;
	os << "Grade to execute : " << obj.getGradeExec() << std::endl;
	return (os);
}
