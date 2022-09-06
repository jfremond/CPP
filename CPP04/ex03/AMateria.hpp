/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 05:44:21 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/06 06:19:40 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string const	_type;
	public:
	AMateria();
	AMateria(std::string const &type);
	AMateria(AMateria const &src);
	AMateria				&operator=(AMateria const &rhs);
	virtual ~AMateria();
	std::string const	&getType() const;
	virtual AMateria	*clone() const = 0;
	virtual void		use(ICharacter &target);
};

#endif
