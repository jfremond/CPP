/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:12:28 by jfremond          #+#    #+#             */
/*   Updated: 2022/06/09 15:18:18 by jfremond         ###   ########.fr       */
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
	Fixed(void);
	Fixed(Fixed const &src);
	Fixed &operator=(Fixed const &rhs);
	~Fixed(void);
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif