/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:42:31 by jfremond          #+#    #+#             */
/*   Updated: 2022/06/06 12:52:33 by jfremond         ###   ########.fr       */
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

void	Harl::_debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger."
		<< "I really do!" << std::endl;
	return ;
}

void	Harl::_info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money."
		<< "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
	return ;	
}

void	Harl::_warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free."
		<< "I’ve been coming for years whereas you started working here since last month." << std::endl;
	return ;
}

void	Harl::_error(void)
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
	return ;
}

void	Harl::_complaining_loop(int index, void (Harl::*functPtr[4])(void), std::string levels[4])
{
	for (int i = index; i < 4; i++)
	{
		std::cout << "[ " << levels[i] << " ]" << std::endl;	
		(this->*functPtr[i])();
		std::cout << std::endl;
	}
}

void	Harl::complain(std::string level)  
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	void (Harl::*functPtr[4])(void) = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	int	index = -1;
	for (int i = 0; i < 4; i++)
	{
		if (!level.compare(levels[i]))
			index = i;
	}
	switch (index)
	{
		case 0:
			_complaining_loop(index, functPtr, levels);
			break;
		case 1:
			_complaining_loop(index, functPtr, levels);
			break;
		case 2:
			_complaining_loop(index, functPtr, levels);
			break;
		case 3:
			_complaining_loop(index, functPtr, levels);
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
	return ;	
}