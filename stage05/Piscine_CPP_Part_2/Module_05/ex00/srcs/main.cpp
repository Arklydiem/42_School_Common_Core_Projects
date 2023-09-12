/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:32:29 by argomez           #+#    #+#             */
/*   Updated: 2023/03/27 13:00:03 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Bureaucrat.hpp"

int main(void)
{
	{
		std::cout << "\e[38;5;42m\t=============== STANDART TESTS =============== \e[0m" << std::endl;

		std::cout << "ONE create without option" << std::endl;
		Bureaucrat	one;
		std::cout << "[ONE]\t" << one << std::endl << std::endl;

		std::cout << "TWO created with option" << std::endl;
		Bureaucrat	two("two", 50);
		std::cout << "[TWO]\t" << two << std::endl << std::endl;

		std::cout << "THREE created by copy" << std::endl;
		Bureaucrat	three(two);
		std::cout << "[THREE]\t" << three << std::endl << std::endl;	

		std::cout << "TWO assign to ONE" << std::endl;
		one = two;
		std::cout << "[ONE]\t" << one << std::endl;
	}
	{
		std::cout << "\e[38;5;42m\t=============== PROMOTE TESTS =============== \e[0m" << std::endl;

		Bureaucrat	president("President", 1);
		Bureaucrat	governor("governor", 50);

		try{
			std::cout << president << std::endl;
			president.promote();
			std::cout << president << std::endl;
		}
		catch(const std::exception& e){
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		try{
			std::cout << governor << std::endl;
			governor.promote();
			std::cout << governor << std::endl;
		}
		catch(const std::exception& e){
			std::cout << e.what() << std::endl;
		}
	}
	{
		std::cout << "\e[38;5;42m\t=============== DEMOTE TESTS =============== \e[0m" << std::endl;

		Bureaucrat	slave("Slave", 150);
		Bureaucrat	governor("governor", 50);

		try{
			std::cout << slave << std::endl;
			slave.demote();
			std::cout << slave << std::endl;
		}
		catch(const std::exception& e){
			std::cout << e.what() << std::endl;
		}
		std::cout << std::endl;
		try{
			std::cout << governor << std::endl;
			governor.demote();
			std::cout << governor << std::endl;
		}
		catch(const std::exception& e){
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
