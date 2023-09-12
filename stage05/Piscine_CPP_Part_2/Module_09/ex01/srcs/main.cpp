/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 12:28:04 by argomez           #+#    #+#             */
/*   Updated: 2023/04/12 12:29:41 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main( int argc, char *argv[] ) {

	try {
		RPN::run(argc, argv);
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	
	
	return 0;
}