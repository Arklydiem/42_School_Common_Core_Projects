/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 11:32:29 by argomez           #+#    #+#             */
/*   Updated: 2023/03/27 13:27:59 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Bureaucrat.hpp"
#include	"Form.hpp"

int main(void)
{
	{
		std::cout << "\e[38;5;42m\t=============== STANDART TESTS =============== \e[0m" << std::endl;

		std::cout << "Papier creation without option :" << std::endl;
		Form	papier;
		std::cout << papier << std::endl << std::endl;

		std::cout << "fourtyNineThree creation with option:" << std::endl;
		Form	fourtyNineThree("49.3", 1, 20);
		std::cout << fourtyNineThree << std::endl << std::endl;

		std::cout << "totalEnergyShadowActions creation by copy of fourtyNineThree:" << std::endl;
		Form	totalEnergyShadowActions(fourtyNineThree);
		std::cout << totalEnergyShadowActions << std::endl << std::endl;

		std::cout << "fourtyNineThree assign to papier :" << std::endl;
		papier = fourtyNineThree;
		std::cout << papier << std::endl << std::endl;
	}
	{
		std::cout << "\e[38;5;42m\t=============== BeSigned TESTS =============== \e[0m" << std::endl;

		Bureaucrat	primeMinister("Borne", 20);
		Bureaucrat	senator("Senator", 60);
		Bureaucrat	totalEnergyPDG("totalEnergyPDG", 15);

		Form	fourtyNineThree("49.3", 15, 20);

		std::cout << primeMinister << std::endl;
		std::cout << senator << std::endl;
		std::cout << totalEnergyPDG << std::endl;
		std::cout << fourtyNineThree << std::endl << std::endl;

		try{
			std::cout << "fourtyNineThree gonna be sign by PrimeMinister" << std::endl;
			fourtyNineThree.beSigned(primeMinister);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
		std::cout << fourtyNineThree << std::endl << std::endl;
		std::cout << std::endl;
		try{
			std::cout << "fourtyNineThree gonna be sign by Senator" << std::endl;
			fourtyNineThree.beSigned(senator);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
		std::cout << fourtyNineThree << std::endl << std::endl;
		std::cout << std::endl;
		try{
			std::cout << "fourtyNineThree gonna be sign by totalEnergyPDG" << std::endl;
			fourtyNineThree.beSigned(totalEnergyPDG);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
		std::cout << fourtyNineThree << std::endl << std::endl;
	}
	{
		std::cout << "\e[38;5;42m\t=============== SignForm TESTS =============== \e[0m" << std::endl;

		Bureaucrat	primeMinister("Borne", 20);
		Bureaucrat	senator("Senator", 60);
		Bureaucrat	totalEnergyPDG("totalEnergyPDG", 15);

		Form	fourtyNineThree("49.3", 15, 20);

		std::cout << primeMinister << std::endl;
		std::cout << senator << std::endl;
		std::cout << totalEnergyPDG << std::endl;
		std::cout << fourtyNineThree << std::endl << std::endl;

		try{
			std::cout << "PrimeMinister gonna sign fourtyNineThree" << std::endl;
			primeMinister.signForm(fourtyNineThree);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
		std::cout << fourtyNineThree << std::endl << std::endl;
		std::cout << std::endl;
		try{
			std::cout << "Senator gonna sign fourtyNineThree" << std::endl;
			senator.signForm(fourtyNineThree);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
		std::cout << fourtyNineThree << std::endl << std::endl;
		std::cout << std::endl;
		try{
			std::cout << "totalEnergyPDG gonna sign fourtyNineThree" << std::endl;
			totalEnergyPDG.signForm(fourtyNineThree);
		}
		catch(const std::exception& e){
			std::cerr << e.what() << '\n';
		}
		std::cout << fourtyNineThree << std::endl;
	}
	return 0;
}
