/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:10:54 by jfremond          #+#    #+#             */
/*   Updated: 2022/07/20 18:34:24 by jfremond         ###   ########.fr       */
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
		int		_nb_contacts;
		int		_oldest;
		Contact	_contacts[8];
		// Functions
		int		_displayHeader(void) const;
		void	_displayContactsInTab(void) const;
		void	_displaySearchResult(void) const;
	public:
		// Constructor and desctructor
		PhoneBook(void);
		~PhoneBook(void);
		// Functions
		void 	addContact(void);
		void	searchContact(void) const;
};

#endif
