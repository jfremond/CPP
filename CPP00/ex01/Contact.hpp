/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:33:03 by jfremond          #+#    #+#             */
/*   Updated: 2022/05/28 10:42:10 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

class Contact
{
	private:
		int			num_contact;
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	public:
		// Getters
		std::string getFirstName(void)
		{
			return first_name;
		}
		std::string getLastName(void)
		{
			return last_name;
		}
		std::string getNickname(void)
		{
			return nickname;
		}
		std::string getPhoneNumber(void)
		{
			return phone_number;
		}
		std::string getDarkestSecret(void)
		{
			return darkest_secret;
		}
		Contact(void);
		~Contact(void);
		void	display(void);
		int	setInfos(int num_contact);
};

#endif