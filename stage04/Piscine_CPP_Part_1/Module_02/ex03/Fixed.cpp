/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 17:33:32 by argomez           #+#    #+#             */
/*   Updated: 2023/03/15 17:08:45 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"
#include <cmath>

Fixed::Fixed(): _value(0){
	return ;
}

Fixed::Fixed(const int fixed){
	this->_value = fixed * ( 1 << this->_shift);
	return ;
}

Fixed::Fixed(const float fixed){
	this->_value = roundf(fixed * ( 1 << this->_shift));
	return ;
}

Fixed::Fixed(const Fixed &obj){
	*this = obj;
	return ;
}

Fixed &Fixed::operator=(const Fixed &obj){
	if (this != &obj)
		this->_value = obj.getRawBits();
	return *this;
}

Fixed Fixed::operator+(const Fixed &obj) const{
	Fixed	newFixed(this->_value + obj._value);
	newFixed._value /= (1 << newFixed._shift);
	return newFixed;
}

Fixed Fixed::operator-(const Fixed &obj) const{
	Fixed	newFixed(this->_value - obj._value);
	newFixed._value /= (1 << newFixed._shift);
	return newFixed;
}

Fixed Fixed::operator*(const Fixed &obj) const{
	Fixed	newFixed(this->_value * obj._value);
	newFixed._value /= (1 << newFixed._shift);
	newFixed._value /= (1 << newFixed._shift);
	return newFixed;
}

Fixed Fixed::operator/(const Fixed &obj) const{
	if (obj._value == 0){
		std::cout << "[Division by zero is undefined] then : ";
		return Fixed(0);
	}
	Fixed	newFixed((float)this->_value / (float)obj._value);
	return newFixed;
}

bool	Fixed::operator>(const Fixed &obj) const{
	return (this->_value > obj._value);
}

bool	Fixed::operator>=(const Fixed &obj) const{
	return (this->_value >= obj._value);
}

bool	Fixed::operator<(const Fixed &obj) const{
	return (this->_value < obj._value);
}

bool	Fixed::operator<=(const Fixed &obj) const{
	return (this->_value <= obj._value);
}

bool	Fixed::operator==(const Fixed &obj) const{
	return (this->_value == obj._value);
}

bool	Fixed::operator!=(const Fixed &obj) const{
	return (this->_value != obj._value);
}

Fixed	Fixed::operator++(){
	this->_value = this->getRawBits() + 1 ;
	return *this;
}

Fixed	Fixed::operator++(int){
	Fixed	newFixed = *this;
	this->_value = this->getRawBits() + 1 ;
	return newFixed;
}

Fixed	Fixed::operator--(){
	this->_value = this->getRawBits() - 1 ;
	return *this;
}

Fixed	Fixed::operator--(int){
	Fixed	newFixed = *this;
	this->_value = this->getRawBits() - 1 ;
	return newFixed;
}

Fixed::~Fixed(){
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

Fixed	Fixed::min(Fixed &a, Fixed &b){
	return (a._value < b._value ? a : b);
}

Fixed	Fixed::min(const Fixed &a, const Fixed &b){
	return (a._value < b._value ? a : b);
}

Fixed	Fixed::max(Fixed &a, Fixed &b){
	return (a._value > b._value ? a : b);
}

Fixed	Fixed::max(const Fixed &a, const Fixed &b){
	return (a._value > b._value ? a : b);
}