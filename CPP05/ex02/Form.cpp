/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:21:59 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/22 18:59:20 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("DefaultForm"), _signed(false), _gradeSign(150), _gradeExec(150)
{
	std::cout << GREEN << "Form default constructor called" << RESET << std::endl;
	return ;
}

Form::Form(std::string const name, int const gts, int const gte) : _name(name), _signed(false), _gradeSign(gts), _gradeExec(gte)
{
	if (this->_gradeSign > 150 || this->_gradeExec > 150)
		throw Form::GradeTooLowException();
	else if (this->_gradeSign < 1 || this->_gradeExec < 1)
		throw Form::GradeTooHighException();
	std::cout << GREEN << "Form " << this->getName() << " string constructor called " << RESET << std::endl;
	return ;	
}

Form::Form(Form const &src) : _name(src.getName()), _gradeSign(src.getGradeSign()), _gradeExec(src.getGradeExec())
{
	std::cout << GREEN << "Form copy constructor called" << RESET << std::endl;
	(*this) = src;
	return ;
}

Form	&Form::operator=(Form const &rhs)
{
	this->_signed = rhs.getSigned();
	return (*this);
}

Form::~Form()
{
	std::cout << RED << "Form " << this->getName() << " destructor called" RESET << std::endl;
	return ;
}

std::string const 	&Form::getName() const
{
	return (this->_name);
}

bool const			&Form::getSigned() const
{
	return (this->_signed);
}

int const			&Form::getGradeSign() const
{
	return (this->_gradeSign);
}

int const			&Form::getGradeExec() const
{
	return (this->_gradeExec);
}

void				Form::beSigned(Bureaucrat const &bc)
{
	if (bc.getGrade() <= this->getGradeSign())
		this->_signed = true;
	else
		throw Form::GradeTooLowException();
}

void				Form::execute(Bureaucrat const &executor) const
{
	if (this->getSigned())
		throw Form::IsNotSignedException();
	else
		std::cout << executor.getName() << " executed " << this->getName() << " form." << std::endl;
}

std::ostream	&operator<<(std::ostream &os, Form const &obj)
{
	os << "Name : " << obj.getName() << std::endl;
	os << "Signed : " << obj.getSigned() << std::endl;
	os << "Grade to sign : " << obj.getGradeSign() << std::endl;
	os << "Grade to execute : " << obj.getGradeExec() << std::endl;
	return (os);
}
