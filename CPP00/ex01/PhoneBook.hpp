/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:10:54 by jfremond          #+#    #+#             */
/*   Updated: 2022/06/02 13:11:06 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>

class PhoneBook
{
	private:
		Contact	_contacts[8];
		int		_nb_contacts;
		int		_oldest;
		// Functions
		int		_displayHeader(void) const;
		void	_displayContactsInTab(void) const;
		void	_displayContactByIndex(void) const;
	public:
		// Constructor and desctructor
		PhoneBook(void);
		~PhoneBook(void);
		// Functions
		void 	addContact(void);
		void	showContacts(void) const;
};

#endif
