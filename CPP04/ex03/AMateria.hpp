/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 03:48:28 by jfremond          #+#    #+#             */
/*   Updated: 2022/08/25 05:17:14 by jfremond         ###   ########.fr       */
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
		std::string _type;
	public:
		AMateria(void);
		AMateria(AMateria const &src);
		AMateria	&operator=(AMateria const &rhs);
		virtual ~AMateria(void);
		virtual AMateria	*clone() const = 0;
		virtual void use(ICharacter &target);
		std::string const	&getType() const;
};

AMateria::AMateria(void)
{
	return ;
}

AMateria::~AMateria(void)
{
	return ;
}

#endif
