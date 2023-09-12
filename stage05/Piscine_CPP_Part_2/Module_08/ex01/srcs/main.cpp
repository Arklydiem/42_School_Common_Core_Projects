/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:28:04 by argomez           #+#    #+#             */
/*   Updated: 2023/04/07 10:04:15 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"


int main( void ) {
	Span sp1 = Span(5);

	try
	{
		sp1.addNumber(6);
		sp1.addNumber(3);
		sp1.addNumber(17);
		sp1.addNumber(9);
		sp1.addNumber(11);
		sp1.displaySpan();
		sp1.addNumber(11);
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << sp1.shortestSpan() << std::endl;
	std::cout << sp1.longestSpan() << std::endl;
	std::cout << std::endl;
	
	Span sp2(150);
	try
	{
		sp2.addNumber(2147483647);
		sp2.addNumber(654);
		sp2.addNumber(179);
		sp2.addNumber(-2147483648);
		sp2.addNumber(101);
		sp2.addNumber(-9815);
		sp2.displaySpan();
		sp2.addNumbers(sp1._intVector.begin(), sp1._intVector.end());
		std::cout << std::endl;
		sp2.displaySpan();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	std::cout << std::endl;
	std::cout << sp2.shortestSpan() << std::endl;
	std::cout << sp2.longestSpan() << std::endl;
	std::cout << std::endl;

	Span sp3(5);
	try
	{
		sp3.addNumbers(sp2._intVector.begin(), sp2._intVector.end());
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	Span sp4(2);
	try
	{
		sp4.addNumber(5);
		sp4.longestSpan();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	Span sp5(2);
	try
	{
		sp5.addNumber(5);
		sp5.shortestSpan();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}

	std::cout << std::endl;

	Span sp6(6);
	try
	{
		sp6.addNumber(5);
		sp6.addNumbers(sp1._intVector.begin(), sp1._intVector.end());
		sp6.displaySpan();
	}
	catch(const std::exception& e)
	{
		std::cout << e.what() << '\n';
	}
	return 0;
}
