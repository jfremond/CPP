/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:42:31 by jfremond          #+#    #+#             */
/*   Updated: 2022/07/26 06:10:11 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

Harl::Harl(void)
{
	return ;
}

Harl::~Harl(void)
{
	return ;
}

void	Harl::_debug(void) const
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger."
		<< "I really do!" << std::endl;
	return ;
}

void	Harl::_info(void) const
{
	std::cout << "I cannot believe adding extra bacon costs more money."
		<< "You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl;
	return ;
}

void	Harl::_warning(void) const
{
	std::cout << "I think I deserve to have some extra bacon for free."
		<< "I've been coming for years whereas you started working here since last month." << std::endl;
	return ;
}

void	Harl::_error(void) const
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	return ;
}

void	Harl::_write_complaint(int index, void (Harl::*functPtr[4])(void) const, std::string levels[4])
{
		std::cout << "[ " << levels[index] << " ]" << std::endl;
		(this->*functPtr[index])();
		std::cout << std::endl;
}

int	getIndex(std::string level, std::string levels[4])
{
	int index = -1;
	for (int i = 0; i < 4; i++)
	{
		if (!level.compare(levels[i]))
			index = i;
	}
	return (index);
}

void	Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functPtr[4])(void) const = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	int	index = getIndex(level, levels);
	switch (index)
	{
		case 0:
			_write_complaint(0, functPtr, levels);
		case 1:
			_write_complaint(1, functPtr, levels);
		case 2:
			_write_complaint(2, functPtr, levels);
		case 3:
			_write_complaint(3, functPtr, levels);
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}
	return ;
}
