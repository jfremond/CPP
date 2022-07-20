/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 17:09:25 by jfremond          #+#    #+#             */
/*   Updated: 2022/07/20 17:51:22 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <cstdlib>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"							/* Black */
#define RED     "\033[31m"							/* Red */
#define GREEN   "\033[32m"							/* Green */
#define YELLOW  "\033[33m"							/* Yellow */
#define BLUE    "\033[34m"							/* Blue */
#define MAGENTA "\033[35m"  					  /* Magenta */
#define CYAN    "\033[36m"  	    			/* Cyan */
#define ORANGE	"\033[38;2;255;165;0m"	/* Orange */

class Contact
{
	private:
		int			contact_id;
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	public:
		Contact(void);
		~Contact(void);
		std::string	checkInfos(int index);
		std::string	getFirstName(void);
		std::string	getLastName(void);
		std::string	getNickname(void);
		std::string	getPhoneNumber(void);
		std::string	getDarkestSecret(void);
		void	displayContact(void);
		int		createNewContact(int nb_contact);
};

int	check_if_digit(std::string str);

#endif
