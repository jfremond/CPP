/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 10:39:36 by jfremond          #+#    #+#             */
/*   Updated: 2022/06/06 12:49:01 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
	private:
		void	_debug(void);
		void	_info(void);
		void	_warning(void);
		void	_error(void);
		void	_complaining_loop(int index, void (Harl::*functPtr[4])(void), std::string levels[4]);
	public:
		Harl(void);
		~Harl(void);
		void	complain(std::string level);
};

#endif