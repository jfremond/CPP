/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 00:51:37 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/09 02:58:52 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
	private:
		AMateria		*_array[4];
		int				_index;
	public:
		MateriaSource();
		MateriaSource(MateriaSource const &src);
		MateriaSource	&operator=(MateriaSource const &rhs);
		virtual ~MateriaSource();
		virtual void			learnMateria(AMateria *m);
		virtual AMateria		*createMateria(std::string const &type);
};

#endif
