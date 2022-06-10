/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 10:08:13 by jfremond          #+#    #+#             */
/*   Updated: 2022/06/10 12:11:28 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
	private:
		Fixed const _x;
		Fixed const	_y;
	public:
		Point(void);
		Point(const float x, const float y);
		Point(Point const &src);
		Point	&operator=(Point const &rhs);
		~Point(void);
		float	getX(void) const;
		float	getY(void) const;
};

//false if point on edge or is vertex
bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif