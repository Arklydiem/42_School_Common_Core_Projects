/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:33:32 by argomez           #+#    #+#             */
/*   Updated: 2023/03/15 17:07:29 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"
#include <cmath>

Fixed::Fixed(): _value(0){
	std::cout << "Default constructor called" << std::endl;
	return ;
}

Fixed::Fixed(const int fixed){
	std::cout << "Int constructor called" << std::endl;
	this->_value = fixed * ( 1 << this->_shift);
	return ;
}

Fixed::Fixed(const float fixed){
	std::cout << "Float constructor called" << std::endl;
	this->_value = roundf(fixed * ( 1 << this->_shift));
	return ;
}

Fixed::Fixed(const Fixed &obj){
	std::cout << "Copy constructor called" << std::endl;
	*this = obj;
	return ;
}

Fixed &Fixed::operator=(const Fixed &obj){
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = obj.getRawBits();
	return *this;
}

Fixed::~Fixed(){
	std::cout << "Destructor Called" << std::endl;
	return ;
}

int	Fixed::getRawBits(void) const{
	return (this->_value);
}

void	Fixed::setRawBits(const int raw){
	this->_value = raw;
}

float	Fixed::toFloat(void) const{
	float value;
	int	power;

	power = (1 << this->_shift);
	value = (float)this->_value / power;
	return (value);
}

int		Fixed::toInt(void) const{
	return (this->_value / ( 1 << this->_shift));
}

std::ostream& operator<<(std::ostream& out, const Fixed& value){
	float res = value.toFloat();
	out << res;
	return out;
}
