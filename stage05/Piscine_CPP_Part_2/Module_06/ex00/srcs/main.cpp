/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:32:29 by argomez           #+#    #+#             */
/*   Updated: 2023/03/28 10:56:26 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "ERROR: need only one string to run." << std::endl;
		return (-1);
	}
	ScalarConverter::convert(argv[1]);
	return 0;
}
