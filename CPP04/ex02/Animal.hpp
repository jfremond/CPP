/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 12:19:54 by jfremond          #+#    #+#             */
/*   Updated: 2022/08/24 12:19:56 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define ORANGE  "\033[38;2;255;165;0m"

class AAnimal
{
	protected:
		std::string	type;
	public:
		AAnimal(void);
		AAnimal(AAnimal const &src);
		AAnimal	&operator=(AAnimal const &rhs);
		virtual ~AAnimal(void);
		virtual void	makeSound(void) const = 0;
		std::string		getType(void) const;
};

#endif
