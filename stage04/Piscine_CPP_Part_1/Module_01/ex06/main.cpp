/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:32:49 by argomez           #+#    #+#             */
/*   Updated: 2023/02/23 13:32:49 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Harl.hpp"

int main(int argc, char **argv){

	if (argc != 2){
		std::cout << "Need only one argument." << std::endl;
		return (0);
	}
    Harl  test;

	test.complain(argv[1]);
	return (0);
}