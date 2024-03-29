/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 12:19:34 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/29 17:07:22 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

int	RobotomyRequestForm::_index = 0;

RobotomyRequestForm::RobotomyRequestForm() : Form()
{
	std::cout << GREEN << "RobotomyRequestForm default constructor called" << RESET << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string const target) : Form(target, 72, 45), _target(target)
{
	std::cout << GREEN << "RobotomyRequestForm " << this->_target << " string constructor called" << RESET << std::endl;
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : Form(src), _target(src._target)
{
	(*this) = src;
	std::cout << GREEN << "RobotomyRequestForm copy constructor called" << RESET << std::endl;
	return ;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	(void)rhs;
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << RED << "RobotomyRequestForm " << this->_target << " destructor called" << RESET << std::endl;
	return ;
}

void		RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	if (!this->getSigned())
		throw Form::IsNotSignedException();
	else if (executor.getGrade() > this->getGradeExec())
		throw Form::GradeTooLowException();
	else
	{
		if (!(this->_index % 2))
			std::cout << this->_target << " has been robotomized." << std::endl;
		else
			std::cout << "The robotomy has failed." << std::endl;
		RobotomyRequestForm::_index++;	
	}
}
