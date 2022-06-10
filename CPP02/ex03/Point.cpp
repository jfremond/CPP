/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:17:39 by jfremond          #+#    #+#             */
/*   Updated: 2022/06/10 12:26:07 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point(void) : _x(0), _y(0)
{
	return ;
}

Point::Point(const float x, const float y) : _x(x), _y(y)
{
	return ;
}

Point::Point(Point const &src) : _x(src.getX()), _y(src.getY())
{
	return ;
}

Point	&Point::operator=(Point const &rhs)
{
	(void)rhs;
	return (*this);
}

Point::~Point(void)
{
	return ;
}

float	Point::getX() const
{
	return (this->_x.toFloat());
}

float	Point::getY() const
{
	return (this->_y.toFloat());
}