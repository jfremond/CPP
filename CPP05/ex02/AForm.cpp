/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 21:21:59 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/22 04:47:20 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("DefaultForm"), _signed(false), _gradeSign(150), _gradeExec(150)
{
	std::cout << GREEN << "Form default constructor called" << RESET << std::endl;
	return ;
}

AForm::AForm(std::string const name, int const gts, int const gte) : _name(name), _signed(false), _gradeSign(gts), _gradeExec(gte)
{
	if (this->_gradeSign > 150 || this->_gradeExec > 150)
		throw AForm::GradeTooLowException();
	else if (this->_gradeSign < 1 || this->_gradeExec < 1)
		throw AForm::GradeTooHighException();
	std::cout << GREEN << "Form " << this->getName() << " string constructor called " << RESET << std::endl;
	return ;	
}

AForm::AForm(AForm const &src) : _name(src.getName()), _gradeSign(src.getGradeSign()), _gradeExec(src.getGradeExec())
{
	std::cout << GREEN << "Form copy constructor called" << RESET << std::endl;
	(*this) = src;
	return ;
}

AForm	&AForm::operator=(AForm const &rhs)
{
	this->_signed = rhs.getSigned();
	return (*this);
}

AForm::~AForm()
{
	std::cout << RED << "Form " << this->getName() << " destructor called" RESET << std::endl;
	return ;
}

std::string const 	&AForm::getName() const
{
	return (this->_name);
}

bool const			&AForm::getSigned() const
{
	return (this->_signed);
}

int const			&AForm::getGradeSign() const
{
	return (this->_gradeSign);
}

int const			&AForm::getGradeExec() const
{
	return (this->_gradeExec);
}

void				AForm::beSigned(Bureaucrat const &bc)
{
	if (bc.getGrade() <= this->getGradeSign())
		this->_signed = true;
	else
		throw AForm::GradeTooLowException();
}

void				AForm::execute(Bureaucrat const &executor) const
{
	std::cout << executor.getName() << " executed " << this->getName() << " form." << std::endl;
}

std::ostream	&operator<<(std::ostream &os, AForm const &obj)
{
	os << "Name : " << obj.getName() << std::endl;
	os << "Signed : " << obj.getSigned() << std::endl;
	os << "Grade to sign : " << obj.getGradeSign() << std::endl;
	os << "Grade to execute : " << obj.getGradeExec() << std::endl;
	return (os);
}
