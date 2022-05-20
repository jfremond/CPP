/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:33:03 by jfremond          #+#    #+#             */
/*   Updated: 2022/05/20 11:02:00 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
	//	int	phone_number;
		std::string	darkest_secret;
	public:
		Contact(void);
		~Contact(void);
};

#endif