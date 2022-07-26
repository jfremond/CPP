/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 06:06:11 by jfremond          #+#    #+#             */
/*   Updated: 2022/07/25 22:39:09 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
	private:
		void	_debug(void) const;
		void	_info(void) const;
		void	_warning(void) const;
		void	_error(void) const;
		void	_write_complaints(int index, void (Harl::*functPtr[4])(void) const,
				std::string levels[4]);
	public:
		Harl(void);
		~Harl(void);
		void	complain(std::string level);
};

#endif
