/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:34:38 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/13 00:46:35 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class AMateria;

class Character : public ICharacter
{
	private:
		std::string const			_name;
		int							_index;
		AMateria					*_stuff[4];
		AMateria					*_floor[4];
	public:
		Character();
		Character(std::string const name);
		Character(Character const &src);
		Character					&operator=(Character const &rhs);
		virtual ~Character();
		virtual std::string const	&getName() const;
		virtual void				equip(AMateria *m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, ICharacter &target);
};

#endif
