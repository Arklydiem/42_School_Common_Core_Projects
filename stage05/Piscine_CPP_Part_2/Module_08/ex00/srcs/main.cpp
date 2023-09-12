/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:28:04 by argomez           #+#    #+#             */
/*   Updated: 2023/04/07 10:01:49 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

#include	<vector>
// #include	<array>			Impossible because : c++11
#include	<deque>
// #include	<forward_list>	Impossible because : c++11
#include	<list>

int main( void ) {
	{
		int myints[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };
		std::vector<int>		intVector (myints, myints + 9);
		// std::array<int, 10>	intArray (myints, myints + 9);
		std::deque<int>			intDeque (myints, myints + 9);
		// std::forward_list<int>	intForwardList (myints, myints + 9);
		std::list<int>			intList (myints, myints + 9);
		
		::easyfind(intVector, 10);
		::easyfind(intVector, 11);
		std::cout << std::endl;
		// ::easyfind(intArray, 20);	
		// ::easyfind(intArray, 22);	
		std::cout << std::endl;
		::easyfind(intDeque, 30);
		::easyfind(intDeque, 33);
		std::cout << std::endl;
		// ::easyfind(intForwardList, 40);
		// ::easyfind(intForwardList, 44);
		std::cout << std::endl;
		::easyfind(intList, 90);
		::easyfind(intList, 99);
		std::cout << std::endl;
	}
	std::cout << std::endl;
	// Impossible because ::easyfind() need two arguments, one typeT and one typeInt
	// {
	// 	std::string mystrings[] = {"Hello", "my", "friends"};
	// 	std::vector<std::string>	stringVector (mystrings, mystrings + 3);
	// 	::easyfind(stringVector, "my");
	// 	::easyfind(stringVector, "LOL");
	// }
	return 0;
}