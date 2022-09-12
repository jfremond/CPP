/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 16:37:44 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/12 16:54:08 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"

class Ice : public AMateria
{
	public:
		Ice();
		Ice(Ice const &src);
		Ice					&operator=(Ice const &rhs);
		virtual ~Ice();
		virtual AMateria	*clone() const;
		virtual void		use(ICharacter &target);
};

#endif
