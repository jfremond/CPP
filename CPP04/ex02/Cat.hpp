/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 02:57:02 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/13 02:57:03 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
	private:
		Brain	*_catBrain;
	public:
		Cat(void);
		Cat(Cat const &src);
		Cat	&operator=(Cat const &rhs);
		virtual ~Cat(void);
		virtual void	makeSound(void) const;
		std::string		getIdea(int index);
		void			setIdea(std::string str, int index);
};

#endif
