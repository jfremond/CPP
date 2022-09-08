/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 06:29:20 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/08 22:47:34 by jfremond         ###   ########.fr       */
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
		~Ice();
		AMateria	*clone() const;
		void		use(ICharacter &target);
};

#endif
