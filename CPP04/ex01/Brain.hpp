/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 20:43:48 by jfremond          #+#    #+#             */
/*   Updated: 2022/08/23 05:39:13 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain
{
	private:
		std::string	_ideas[1000];
	public:
	Brain(void);
	Brain(Brain const &src);
	Brain	&operator=(Brain const &rhs);
	~Brain(void);
	std::string	getIdea(int index);
	std::string	*getAddress();
	void		setIdea(std::string str, int index);
};

#endif
