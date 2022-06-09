/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:12:28 by jfremond          #+#    #+#             */
/*   Updated: 2022/06/09 20:12:26 by jfremond         ###   ########.fr       */
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
	//! 6 comparison operators
	bool operator>(Fixed const &rhs) const; 
	bool operator<(Fixed const &rhs) const;
	bool operator>=(Fixed const &rhs) const;
	bool operator<=(Fixed const &rhs) const;
	bool operator==(Fixed const &rhs) const;
	bool operator!=(Fixed const &rhs) const;
	//! 4 arithmetic operators
	Fixed operator+(Fixed const &rhs) const;
	Fixed operator-(Fixed const &rhs) const;
	Fixed operator*(Fixed const &rhs) const;
	Fixed operator/(Fixed const &rhs) const;
	//! 4 increment/decrement operators
	Fixed &operator++(); 	// ++val
	Fixed operator++(int);	// val++
	Fixed &operator--();	// --val
	Fixed operator--(int);	// val--
	~Fixed(void);
	float	toFloat(void) const;
	int		toInt(void) const;
	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	//! min and max
	static Fixed	&min(Fixed &a, Fixed &b);
	static const Fixed		&min(Fixed const &a, Fixed const &b);
	static Fixed	&max(Fixed &a, Fixed &b);
	static const Fixed		&max(Fixed const &a, Fixed const &b);
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif