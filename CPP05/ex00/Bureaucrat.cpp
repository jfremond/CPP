/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 04:41:09 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/20 04:50:23 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Crat"), _grade(150)
{
	std::cout << GREEN << "Bureaucrat default constructor called" << RESET << std::endl;
	return ;	
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name), _grade(grade)
{
	this->checkGrade();
	std::cout << GREEN << "Bureaucrat " << this->_name << " string constructor called" << RESET << std::endl;
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src.getName())
{
	(*this)	= src;
	std::cout << GREEN << "Bureaucrat copy constructor called" << RESET << std::endl;
	return ;
}

Bureaucrat			&Bureaucrat::operator=(Bureaucrat const &rhs)
{
	this->_grade = rhs.getGrade();
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << RED << "Bureaucrat " << this->getName() << " destructor called" << RESET << std::endl;
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

std::ostream 	&operator<<(std::ostream &os, Bureaucrat const &obj)
{
	os << obj.getName() << ", bureaucrat grade " << obj.getGrade() << "." << std::endl;	
	return (os);
}
