/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 00:05:54 by jfremond          #+#    #+#             */
/*   Updated: 2022/08/19 05:49:24 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string	ideas[100];
	public:
		Brain(void);
		Brain(Brain const &src);
		Brain	&operator=(Brain const &rhs);
		~Brain(void);
		std::string	getIdea(int i) const;
		std::string	*getAddress(int i);
};

#endif
