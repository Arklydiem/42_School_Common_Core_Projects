/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 10:47:07 by argomez           #+#    #+#             */
/*   Updated: 2023/03/09 16:02:14 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Point.hpp"

Point::Point(): _x(0), _y(0){
	return ;
}

Point::Point(const float a, const float b): _x(a), _y(b){
	return ;
}

Point::Point(const Point &obj) : _x(obj._x), _y(obj._y){
	return ;
}

Point &Point::operator=(const Point &obj){
	if (this != &obj){
		(Fixed)this->_x = obj._x;
		(Fixed)this->_y = obj._y;
	}
	return *this;
}

Point::~Point(){
	return ;
}

float	Point::getx() const{
	return (this->_x.getRawBits());
}

float	Point::gety() const{
	return (this->_y.getRawBits());
}