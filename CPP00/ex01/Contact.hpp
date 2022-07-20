/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:33:03 by jfremond          #+#    #+#             */
/*   Updated: 2022/07/20 18:18:17 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"				/* Black */
#define RED     "\033[31m"				/* Red */
#define GREEN   "\033[32m"				/* Green */
#define YELLOW  "\033[33m"				/* Yellow */
#define BLUE    "\033[34m"				/* Blue */
#define MAGENTA "\033[35m"  			/* Magenta */
#define CYAN    "\033[36m"  	    	/* Cyan */
#define ORANGE	"\033[38;2;255;165;0m"	/* Orange */

class Contact
{
	private:
		int			_contact_id;
		std::string	_first_name;
		std::string	_last_name;
		std::string	_nickname;
		std::string	_phone_number;
		std::string	_darkest_secret;
	public:
		// Constructor and destructor
		Contact(void);
		~Contact(void);
		// Getters
		std::string getFirstName(void) const;
		std::string getLastName(void) const;
		std::string getNickname(void) const;
		std::string getPhoneNumber(void) const;
		std::string getDarkestSecret(void) const;
		// Functions
		void		displayContact(void) const;
		std::string	checkInfos(int index);
		int			createNewContact(int contact_id);
		static int	check_if_digit(std::string str);
};

#endif