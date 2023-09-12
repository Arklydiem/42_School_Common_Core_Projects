/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:48:10 by argomez           #+#    #+#             */
/*   Updated: 2023/03/09 15:31:37 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
	public:
		Fixed();
		Fixed(const int fixed);
		Fixed(const float fixed);
		Fixed(const Fixed &obj);
		Fixed	&operator=(const Fixed &obj);
		Fixed	operator+(const Fixed &obj) const;
		Fixed	operator-(const Fixed &obj) const;
		Fixed	operator*(const Fixed &obj) const;
		Fixed	operator/(const Fixed &obj) const;
		bool	operator>(const Fixed &obj) const;
		bool	operator>=(const Fixed &obj) const;
		bool	operator<(const Fixed &obj) const;
		bool	operator<=(const Fixed &obj) const;
		bool	operator==(const Fixed &obj) const;
		bool	operator!=(const Fixed &obj) const;
		Fixed	operator++();
		Fixed	operator++(int);
		Fixed	operator--();
		Fixed	operator--(int);
		~Fixed();
		int		getRawBits(void) const;
		void	setRawBits(const int raw);
		float	toFloat(void) const;
		int		toInt(void) const;
		static Fixed	min(Fixed &a, Fixed &b);
		static Fixed	min(const Fixed &a, const Fixed &b);
		static Fixed	max(Fixed &a, Fixed &b);
		static Fixed	max(const Fixed &a, const Fixed &b);
	private:
		int					_value;
		static const int	_shift = 8;
};

std::ostream& operator<<(std::ostream& out, const Fixed& value);

#endif