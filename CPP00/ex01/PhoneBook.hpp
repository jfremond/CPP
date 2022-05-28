/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 18:46:58 by jfremond          #+#    #+#             */
/*   Updated: 2022/05/19 22:04:26 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYAWESOMEPHONEBOOK_HPP
#define MYAWESOMEPHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <string>

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		nb_contacts;
		int		oldest;
	public:
		// Constructor and desctructor
		PhoneBook(void);
		~PhoneBook(void);
		// Functions
		void 	addContact(void);
		int		displayHeader(void);
		void	displayContactsInTab(void);
		void	displayContactByIndex(void);
		void	showContacts(void);
};

#endif