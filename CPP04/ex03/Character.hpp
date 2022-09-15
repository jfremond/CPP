/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 17:34:38 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/15 22:54:49 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
// #include "AMateria.hpp"

class AMateria;

class Character : public ICharacter
{
	private:
		std::string					_name;
		int							_index;
		AMateria					*_stuff[4];
		AMateria					*_floor;
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
		void						cleanFloor();
};

#endif
