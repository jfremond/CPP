/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 02:56:50 by jfremond          #+#    #+#             */
/*   Updated: 2022/09/13 02:56:51 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string	_ideas[100];
	public:
		Brain(void);
		Brain(Brain const &src);
		Brain	&operator=(Brain const &rhs);
		~Brain(void);
		std::string	getIdea(int index);
		void		setIdea(std::string str, int index);
};

#endif
