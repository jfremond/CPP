/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:47:07 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/16 04:44:37 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default"), _grade(150)
{
	std::cout << GREEN << "Bureaucrat default constructor called" << RESET << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade)
{
	this->checkGrade();
	std::cout << GREEN << "Bureaucrat " << this->_name << " constructor called" << RESET << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src._name + "_cpy")
{
	std::cout << GREEN << "Bureaucrat " << src.getName() << " copy constructor called" << RESET << std::endl;
	(*this) = src;
	return ;
}

Bureaucrat	&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	this->_grade = rhs._grade;
	std::cout << "Name can't be assigned, becomes \"name + _cpy\"" << std::endl;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "Bureaucrat " << this->_name << " destructor called" << RESET << std::endl;
	return ;
}

std::string const	&Bureaucrat::getName() const
{
	return (this->_name);
}

int	const			&Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void				Bureaucrat::incrementGrade()
{
	this->_grade--;
	this->checkGrade();
}

void				Bureaucrat::decrementGrade()
{
	this->_grade++;
	this->checkGrade();		
}

void				Bureaucrat::checkGrade()
{
	if (this->_grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (this->_grade > 150)
		throw Bureaucrat::GradeTooLowException();	
}

void				Bureaucrat::signForm(AForm &form)
{
	if (form.getSigned() == true)
		std::cout << "Bureaucrat " << this->_name << " couldn't sign the form because it is already signed" << std::endl;
	else
	{
		try
		{
			form.beSigned(*this);
			std::cout << this->_name << " signed " << form.getName() << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cout << this->getName() << " can't sign " << form.getName() << " because " << e.what() << std::endl;
		}
	}
		
}

std::ostream &operator<<(std::ostream &os, Bureaucrat const &obj)
{
	os << obj.getName() << ", grade " << obj.getGrade() << "." << std::endl;
	return (os);
}
