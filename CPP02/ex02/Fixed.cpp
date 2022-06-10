/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 15:21:14 by jfremond          #+#    #+#             */
/*   Updated: 2022/06/10 14:54:51 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int	Fixed::_bits = 8;

Fixed::Fixed(void) : _value(0)
{
	return ;
}

Fixed::Fixed(const int val) : _value(val << this->_bits)
{
	return ;
}

Fixed::Fixed(const float val) : _value(roundf(val * (1 << this->_bits)))
{
	return ;
}

Fixed::Fixed(Fixed const &src)
{
	*this = src;
	return ;
}

Fixed::~Fixed(void)
{
	return ;
}

int	Fixed::getRawBits(void) const
{
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
	return ;
}

float	Fixed::toFloat(void) const
{
	return ((float)this->_value / (float)(1 << this->_bits));
}

int	Fixed::toInt(void) const
{
	return (this->_value >> this->_bits);
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
	if (this != &rhs)
		this->_value = rhs.getRawBits();
	return (*this);
}

bool	Fixed::operator>(Fixed const &rhs) const
{
	if (this->_value > rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<(Fixed const &rhs) const
{
	if (this->_value < rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator>=(Fixed const &rhs) const
{
	if (this->_value >= rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
	if (this->_value <= rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator==(Fixed const &rhs) const
{
	if (this->_value == rhs.getRawBits())
		return (true);
	return (false);
}

bool	Fixed::operator!=(Fixed const &rhs) const
{
	if (this->_value != rhs.getRawBits())
		return (true);
	return (false);
}

Fixed	Fixed::operator+(Fixed const &rhs) const
{
	return (this->toFloat() + rhs.toFloat());
}

Fixed	Fixed::operator-(Fixed const &rhs) const
{
	return (this->toFloat() - rhs.toFloat());
}

Fixed	Fixed::operator*(Fixed const &rhs) const
{	
	return (this->toFloat() * rhs.toFloat());
}

Fixed	Fixed::operator/(Fixed const &rhs) const
{
	return (this->toFloat() / rhs.toFloat());
}

Fixed	&Fixed::operator++()
{
	this->_value++;
	return (*this);	
}

Fixed	Fixed::operator++(int)
{
	Fixed	tmp = *this;
	++*this;
	return (tmp);	
}

Fixed	&Fixed::operator--()
{
	this->_value--;
	return (*this);	
}

Fixed	Fixed::operator--(int)
{
	Fixed	tmp = *this;
	--*this;
	return (tmp);	
}

Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	if (a.toFloat() <= b.toFloat())
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() <= b.toFloat())
		return (a);
	else
		return (b);	
}

Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	if (a.toFloat() >= b.toFloat())
		return (a);
	else
		return (b);
}

const Fixed	&Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.toFloat() > b.toFloat())
		return (a);
	else
		return (b);	
}

std::ostream &operator<<(std::ostream &o, Fixed const &i)
{
	o << i.toFloat();
	return (o);
}