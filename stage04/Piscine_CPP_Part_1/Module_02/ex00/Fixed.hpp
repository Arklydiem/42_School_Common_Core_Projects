/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:48:10 by argomez           #+#    #+#             */
/*   Updated: 2023/03/13 09:19:25 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed
{
	public:
	
		Fixed();
		Fixed(const Fixed &);
		Fixed &operator=(const Fixed&);
		~Fixed();

		int		getRawBits(void) const;
		
		void	setRawBits(const int raw);
	private:
	
		int					_value;
		static const int	_shift = 8;
};