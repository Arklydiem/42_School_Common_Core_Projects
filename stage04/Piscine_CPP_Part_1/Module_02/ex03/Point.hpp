/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 11:16:24 by argomez           #+#    #+#             */
/*   Updated: 2023/03/09 15:59:19 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		POINT_HPP
# define	POINT_HPP

# include	"./Fixed.hpp"

class Point
{
	public:
		Point ();
		Point (const float a, const float b);
		Point (const Point&);
		~Point ();
		Point &operator=(const Point&);
		float	getx() const;
		float	gety() const;
	private:
		const Fixed	_x;
		const Fixed	_y;
};

#endif