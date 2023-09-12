/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:28:04 by argomez           #+#    #+#             */
/*   Updated: 2023/03/31 16:01:51 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main( void ) {
	Array<int> intTest1;
	
	try
	{
		std::cout << "intTest 1 :" << std::endl;
		for (size_t i = 0; i < 5; i++)
			std::cout << intTest1[i] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	Array<int> intTest2(5);
	
	try
	{
		std::cout << "intTest 2 :" << std::endl;
		for (size_t i = 0; i < 5; i++)
			std::cout << intTest2[i] << std::endl;
		std::cout << std::endl;
		for (size_t i = 0; i < 5; i++)
			intTest2[i] = i * i;
		std::cout << "intTest 2 :" << std::endl;
		for (size_t i = 0; i < 5; i++)
			std::cout << intTest2[i] << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	intTest1 = intTest2;

	try
	{
		std::cout << "intTest 1 :" << std::endl;
		for (size_t i = 0; i < 5; i++)
			std::cout << intTest1[i] << std::endl;
		std::cout << std::endl;
		for (size_t i = 0; i < 5; i++)
			intTest1[i] += 9;
		std::cout << "intTest 1 :" << std::endl;
		for (size_t i = 0; i < 5; i++)
			std::cout << intTest1[i] << std::endl;
		std::cout << "intTest 2 :" << std::endl;
		for (size_t i = 0; i < 5; i++)
			std::cout << intTest2[i] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	Array<std::string> stringTest(5);
	
	try
	{
		std::cout << "stringTest :" << std::endl;
		for (size_t i = 0; i < 5; i++)
			std::cout << stringTest[i] << std::endl;
		std::cout << std::endl;
		for (size_t i = 0; i < 5; i++)
			stringTest[i] = "BONJOUR";
		std::cout << "stringTest :" << std::endl;
		for (size_t i = 0; i < 5; i++)
			std::cout << stringTest[i] << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
