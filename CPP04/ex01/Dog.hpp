/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:13:17 by jfremond          #+#    #+#             */
/*   Updated: 2022/08/24 11:31:54 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
	private:
		Brain	*_dogBrain;
	public:
		Dog(void);
		Dog(Dog const &src);
		Dog	&operator=(Dog const &rhs);
		virtual ~Dog(void);
		virtual void	makeSound(void) const;
		std::string		getIdea(int index);
		std::string		*getAddress(void);
		void			setIdea(std::string str, int index);
};

#endif
