/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 16:20:30 by argomez           #+#    #+#             */
/*   Updated: 2023/03/13 15:21:10 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Fixed.hpp"
#include <iomanip>

int main( void ) {
	
	{
		Fixed a;
		Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
		
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << Fixed::max( a, b ) << std::endl;
	}

	std::cout << std::endl;

	{
		Fixed	testA(3.8f);
		Fixed	testB(2.5f);
		Fixed	testC(2);
		Fixed	testD(0);
		const Fixed	testE(42);
		const Fixed	testF(69);

		std::cout << "Values are :" << std::endl;
		std::cout << "test A = " << testA << std::endl;
		std::cout << "test B = " << testB << std::endl;
		std::cout << "test C = " << testC << std::endl;
		std::cout << "test D = " << testD << std::endl;
		std::cout << "test E = " << testE << std::endl;
		std::cout << "test F = " << testF << std::endl;

		bool result;
		std::cout << std::endl << "Arithmetic tests are : " << std::endl;

		std::cout << testA << " + " << testB << " = " << testA + testB << std::endl;
		std::cout << testA << " + " << testC << " = " << testA + testC << std::endl;
		std::cout << testA << " + " << testD << " = " << testA + testD << std::endl;
		std::cout << std::endl;

		std::cout << testA << " - " << testB << " = " << testA - testB << std::endl;
		std::cout << testA << " - " << testC << " = " << testA - testC << std::endl;
		std::cout << testA << " - " << testD << " = " << testA - testD << std::endl;
		std::cout << std::endl;

		std::cout << testA << " * " << testB << " = " << testA * testB << std::endl;
		std::cout << testA << " * " << testC << " = " << testA * testC << std::endl;
		std::cout << testA << " * " << testD << " = " << testA * testD << std::endl;
		std::cout << std::endl;

		std::cout << testA << " / " << testB << " = " << testA / testB << std::endl;
		std::cout << testA << " / " << testC << " = " << testA / testC << std::endl;
		std::cout << testA << " / " << testD << " = " << testA / testD << std::endl;
		std::cout << std::endl;


		std::cout << std::endl << "Comparaison tests are : " << std::endl;
		result = testA > testB;
		std::cout << testA << " > " << testB << " = " << result << std::endl;
		result = testB > testA;
		std::cout << testB << " > " << testA << " = " << result << std::endl;
		result = testB > testC;
		std::cout << testB << " > " << testC << " = " << result << std::endl;
		std::cout << std::endl;

		result = testA >= testB;
		std::cout << testA << " >= " << testB << " = " << result << std::endl;
		result = testB >= testA;
		std::cout << testB << " >= " << testA << " = " << result << std::endl;
		result = testB >= testC;
		std::cout << testB << " >= " << testC << " = " << result << std::endl;
		std::cout << std::endl;

		result = testA < testB;
		std::cout << testA << " < " << testB << " = " << result << std::endl;
		result = testB < testA;
		std::cout << testB << " < " << testA << " = " << result << std::endl;
		result = testB < testC;
		std::cout << testB << " < " << testC << " = " << result << std::endl;
		std::cout << std::endl;

		result = testA <= testB;
		std::cout << testA << " <= " << testB << " = " << result << std::endl;
		result = testB <= testA;
		std::cout << testB << " <= " << testA << " = " << result << std::endl;
		result = testB <= testC;
		std::cout << testB << " <= " << testC << " = " << result << std::endl;
		std::cout << std::endl;

		result = testA == testB;
		std::cout << testA << " == " << testB << " = " << result << std::endl;
		result = testB == testA;
		std::cout << testB << " == " << testA << " = " << result << std::endl;
		result = testB == testC;
		std::cout << testB << " == " << testC << " = " << result << std::endl;
		std::cout << std::endl;

		result = testA != testB;
		std::cout << testA << " != " << testB << " = " << result << std::endl;
		result = testB != testA;
		std::cout << testB << " != " << testA << " = " << result << std::endl;
		result = testB != testC;

		std::cout << testB << " != " << testC << " = " << result << std::endl;

		std::cout << std::endl << "Incrementation and Decrementation tests are : " << std::endl;
		std::cout << "testA++" << " : " << testA << " -> " << testA++ << " -> " << testA << std::endl;
		std::cout << "testB++" << " : " << testB << " -> " << testB++ << " -> " << testB << std::endl;
		std::cout << "testC++" << " : " << testC << " -> " << testC++ << " -> " << testC << std::endl;
		std::cout << "testD++" << " : " << testD << " -> " << testD++ << " -> " << testD << std::endl;
		std::cout << std::endl;
		std::cout << "++testA" << " : " << testA << " -> "<< ++testA << " -> " << testA << std::endl;
		std::cout << "++testB" << " : " << testB << " -> "<< ++testB << " -> " << testB << std::endl;
		std::cout << "++testC" << " : " << testC << " -> "<< ++testC << " -> " << testC << std::endl;
		std::cout << "++testD" << " : " << testD << " -> "<< ++testD << " -> " << testD << std::endl;
		std::cout << std::endl;
		std::cout << "testA--" << " : " << testA << " -> "<< testA-- << " -> " << testA << std::endl;
		std::cout << "testB--" << " : " << testB << " -> "<< testB-- << " -> " << testB << std::endl;
		std::cout << "testC--" << " : " << testC << " -> "<< testC-- << " -> " << testC << std::endl;
		std::cout << "testD--" << " : " << testD << " -> "<< testD-- << " -> " << testD << std::endl;
		std::cout << std::endl;
		std::cout << "--testA" << " : " << testA << " -> "<< --testA << " -> " << testA << std::endl;
		std::cout << "--testB" << " : " << testB << " -> "<< --testB << " -> " << testB << std::endl;
		std::cout << "--testC" << " : " << testC << " -> "<< --testC << " -> " << testC << std::endl;
		std::cout << "--testD" << " : " << testD << " -> "<< --testD << " -> " << testD << std::endl;
		std::cout << std::endl;

		std::cout << std::endl << "Min and Max tests are : " << std::endl;
		std::cout << "simple min : " << testA << " or " << testB << " -> " << Fixed::min( testA, testB ) << std::endl;
		std::cout << "const  min : " << testE << " or " << testF << " -> " << Fixed::min( testE, testF ) << std::endl;
		std::cout << "simple max : " << testC << " or " << testD << " -> " << Fixed::max( testC, testD ) << std::endl;
		std::cout << "const  max : " << testA << " or " << testF << " -> " << Fixed::max( testA, testF ) << std::endl;

		std::cout << std::endl;
	}

	std::cout << std::endl;

	{
		Fixed a(-1);
		std::cout << a << std::endl;
		std::cout << ++a << std::endl;
		std::cout << a << std::endl;
		std::cout << a++ << std::endl;
		std::cout << a << std::endl;
	}
	
	return 0;
}