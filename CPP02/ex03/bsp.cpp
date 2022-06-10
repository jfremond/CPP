/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfremond <jfremond@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:24:32 by jfremond          #+#    #+#             */
/*   Updated: 2022/06/10 13:24:18 by jfremond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

float	calculate_area(Point const a, Point const b, Point const c)
{
	float	area;
	// area = (a.x(b.y - c.y) + b.x(c.y - a.y) + c.x(a.y - b.y)) / 2;
	area = (a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())) / 2;
	if (area < 0)
		area *= -1.0f;
	return (area);
}

bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	area_abc = calculate_area(a, b, c);
	float	area_abp = calculate_area (a, b, point);
	float	area_acp = calculate_area(a, c, point);
	float	area_bcp = calculate_area(b, c, point);

	if (area_abp == 0 || area_acp == 0 || area_bcp == 0)
		return (false);	
	if (area_abp + area_acp + area_bcp != area_abc)
		return (false);	
	return (true);
}