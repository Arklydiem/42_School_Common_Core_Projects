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

int main(void){
    Harl  test;

	test.complain("DEBUG");
	test.complain("ERROR");
	test.complain("INFO");
	test.complain("WARNING");
	test.complain("DEBUG");
	test.complain("INFO");
	test.complain("WARNING");
	test.complain("DEBUG");
	test.complain("ERROR");
	test.complain("INFO");
	test.complain("CECI EST UNE ERROR");
	test.complain("Ca aussi");
	return (0);
}