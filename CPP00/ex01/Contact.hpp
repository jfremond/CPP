/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:33:03 by jfremond          #+#    #+#             */
/*   Updated: 2022/05/26 12:59:26 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

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
		// Setters
		void	setFirstName(std::string f_name)
		{
			first_name = f_name;	
		}
		void	setLastName(std::string l_name)
		{
			last_name = l_name;
		}
		void	setNickname(std::string n_name)
		{
			nickname = n_name;
		}
		void	setPhoneNumber(std::string number)
		{
			phone_number = number;
		}
		void	setDarkestSecret(std::string secret)
		{
			darkest_secret = secret;
		}
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
		void	display(void)
		{
			std::cout << "First name : " << first_name << std::endl;
			std::cout << "Last name : " << last_name << std::endl;
			std::cout << "Nickname : " << nickname << std::endl;
			std::cout << "Phone number : " << phone_number << std::endl;
			std::cout << "Darkest secret : " << darkest_secret << std::endl;
		}
		Contact(void);
		int	setInfos(int num_contact);
		~Contact(void);
};

#endif