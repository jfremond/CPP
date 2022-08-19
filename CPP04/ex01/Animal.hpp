/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 02:58:03 by jfremond          #+#    #+#             */
/*   Updated: 2022/08/18 21:52:17 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string	type;
	public:
		Animal(void);
		Animal(Animal const &src);
		Animal	&operator=(Animal const &rhs);
		virtual ~Animal(void);
		virtual void	makeSound(void) const;
		std::string		getType(void) const;
};

#endif
