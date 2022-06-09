/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 23:39:10 by jfremond          #+#    #+#             */
/*   Updated: 2022/06/09 23:55:30 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		const Fixed	_x;
		const Fixed	_y;
	public:
		Point(void);
		Point(const float x, const float y);
		Point(Point const &src);
		~Point(void);
		Point	&operator=(Point const &rhs);
		int		getX(void) const;
		int		getY(void) const;
};

bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif