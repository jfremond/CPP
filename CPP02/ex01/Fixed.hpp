/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:12:28 by jfremond          #+#    #+#             */
/*   Updated: 2022/06/09 18:44:11 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					_value;
		static const int	_bits;
	public:
	Fixed(void);
	Fixed(const int val);
	Fixed(const float val);
	Fixed(Fixed const &src);
	Fixed &operator=(Fixed const &rhs);
	~Fixed(void);
	float	toFloat(void) const;
	int		toInt(void) const;
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif