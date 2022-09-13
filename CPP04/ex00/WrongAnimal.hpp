/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 02:52:03 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/13 02:52:04 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string	type;
	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const &src);
		WrongAnimal	&operator=(WrongAnimal const &rhs);
		~WrongAnimal(void);
		void	makeSound(void) const;
		std::string getType(void) const;
};

#endif
