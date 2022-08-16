/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 08:45:25 by jfremond          #+#    #+#             */
/*   Updated: 2022/08/16 01:03:20 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CLAPTRAP_CPP
#define	CLAPTRAP_CPP

#define RESET   "\033[0m"
#define BLACK   "\033[30m"				/* Black */
#define RED     "\033[31m"				/* Red */
#define GREEN   "\033[32m"				/* Green */
#define YELLOW  "\033[33m"				/* Yellow */
#define BLUE    "\033[34m"				/* Blue */
#define MAGENTA "\033[35m"  			/* Magenta */
#define CYAN    "\033[36m"  	    	/* Cyan */
#define ORANGE	"\033[38;2;255;165;0m"	/* Orange */

#include <iostream>

class ClapTrap
{
	protected:
		std::string		_name;
		unsigned int	_hitPts;
		unsigned int	_enPts;
		unsigned int	_atkDmg;
		ClapTrap(void);
	public:
		ClapTrap(std::string name);
		ClapTrap(ClapTrap const &src);
		ClapTrap	&operator=(ClapTrap const &rhs);
		~ClapTrap(void);
		void		attack(const std::string &target);
		void		takeDamage(unsigned int amount);
		void		beRepaired(unsigned int amount);
		std::string	getName(void) const;
		unsigned int	getHitPts(void) const;
		unsigned int	getEnPts(void) const;
		unsigned int	getAtkDmg(void) const;
};

#endif
