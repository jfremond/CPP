/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:12:28 by jfremond          #+#    #+#             */
/*   Updated: 2022/06/09 23:07:54 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
	private:
		int					_value;
		static const int	_bits;
	public:
		// Constructors and destructor
		Fixed(void);
		Fixed(Fixed const &src);
		~Fixed(void);
		// Getter and setter
		int					getRawBits(void) const;
		void				setRawBits(int const raw);
		// Assignation operator overload
		Fixed				&operator=(Fixed const &rhs);
};

#endif