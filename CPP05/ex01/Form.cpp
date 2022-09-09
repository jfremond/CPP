/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 18:12:33 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/06 01:42:38 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("DefaultForm"), _signed(false), _signGrade(150), _signExec(150)
{
	std::cout << GREEN << "Form default constructor called" << RESET << std::endl;
	return ;
}

Form::Form(std::string const name, int const gts, int const gte) : _name(name), _signed(false), _signGrade(gts), _signExec(gte)
{
	this->checkGrades();
	std::cout << GREEN << "Form " << this->_name << " constructor called" << RESET << std::endl;
	return ;
}

Form::Form(Form const &src) : _name(src._name + "_cpy"), _signGrade(src._signGrade), _signExec(src._signExec)
{
	std::cout << GREEN << "Form " << src.getName() << " copy constructor called" << RESET << std::endl;
	(*this) = src;
	return ;
}

Form	&Form::operator=(Form const &rhs)
{
	this->_signed = rhs._signed;
	std::cout << GREEN << "Name and grades can't be assigned\n" 
		<< "Name becomes \"name + _cpy\"" << RESET << std::endl;
	return (*this);
}

Form::~Form()
{
	std::cout << RED << "Form " << this->_name << " destructor called" << RESET << std::endl;
	return ;
}

std::string const	&Form::getName() const
{
	return (this->_name);
}

bool const			&Form::getSigned() const
{
	return (this->_signed);
}

int const			&Form::getExecGrade() const
{
	return (this->_signGrade);
}

int const			&Form::getSignGrade() const
{
	return (this->_signExec);
}

void				Form::checkGrades() const
{
	if (this->_signGrade < 1 || this->_signExec < 1)
		throw Form::GradeTooHighException();
	else if (this->_signGrade > 150 || this->_signExec > 150)
		throw Form::GradeTooLowException();
}

void				Form::beSigned(Bureaucrat const &bc)
{
	if (this->getSigned())
	{
		std::cout << CYAN << "The form \"" << this->_name << "\" has already been signed" << RESET << std::endl;
		return ;
	}
	try
	{
		if (bc.getGrade() > this->getExecGrade())
	{
		std::cout << bc.getName() << " couldn't sign " << this->_name
			<< " because ";
		throw Form::GradeTooLowException();
	}
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	this->_signed = true;
}

std::ostream	&operator<<(std::ostream &os, Form const &obj)
{
	os << "Name of the form: " << obj.getName() << std::endl;
	os << "Grade to sign : " << obj.getExecGrade() << std::endl;
	os << "Grade to execute : " << obj.getSignGrade() << std::endl;
	if (!obj.getSigned())
		os << "The form \"" << obj.getName() << "\" hasn't been signed yet" << std::endl;
	else
		os << "The form \"" << obj.getName() << "\" has been signed" << std::endl;
	os << "The form \"" << obj.getName() << "\" has yet to be executed" << std::endl;
	return (os);
}