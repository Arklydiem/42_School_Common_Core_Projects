/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 10:41:01 by argomez           #+#    #+#             */
/*   Updated: 2023/03/28 17:36:58 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SCALARCONVERTER_HPP
# define	SCALARCONVERTER_HPP

# include	<iostream>
# include	<iomanip>
# include	<string>
# include	<cstdlib>
# include	<cctype>
# include	<cmath>

# define	CHAR	1
# define	INT		2
# define	FLOAT	3
# define	DOUBLE	4

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter& obj);
		ScalarConverter* operator=(const ScalarConverter& obj);
		~ScalarConverter();
	public:
		static void	convert(std::string toConvert);
};

#endif
