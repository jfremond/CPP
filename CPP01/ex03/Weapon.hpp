/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 00:07:53 by jfremond          #+#    #+#             */
/*   Updated: 2022/07/25 12:57:40 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>

class Weapon
{
	private:
		std::string	_type;
	public:
		Weapon(void);
		Weapon(std::string type);
		~Weapon(void);
		std::string	const &getType() const;
		void		setType(std::string type);
};

#endif