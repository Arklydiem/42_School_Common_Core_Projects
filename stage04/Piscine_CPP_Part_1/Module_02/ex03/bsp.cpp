/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:36:28 by argomez           #+#    #+#             */
/*   Updated: 2023/03/09 15:56:26 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./Point.hpp"

bool bsp( const Point a, const Point b, const Point c, const Point point ){
	Fixed	state[3];

	state[0] = (c.getx()-point.getx())*(a.gety()-point.gety())-(c.gety()-point.gety())*(a.getx()-point.getx());
	state[1] = (a.getx()-point.getx())*(b.gety()-point.gety())-(a.gety()-point.gety())*(b.getx()-point.getx());
	state[2] = (b.getx()-point.getx())*(c.gety()-point.gety())-(b.gety()-point.gety())*(c.getx()-point.getx());

	if (state[0] > 0 && state[1] > 0 && state[2] > 0)
		return (1);
	else if (state[0] < 0 && state[1] < 0 && state[2] < 0)
		return (1);
	return (0);
}
