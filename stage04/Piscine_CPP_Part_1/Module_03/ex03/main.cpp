/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:34:35 by argomez           #+#    #+#             */
/*   Updated: 2023/03/13 12:32:09 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"./ClapTrap.hpp"
#include	"./ScavTrap.hpp"
#include	"./FragTrap.hpp"

int main(void)
{
	ClapTrap clapy("clapy");
	ScavTrap scavy("scavy");
	FragTrap fragy("fragy");

	clapy.attack("target 1");
	scavy.attack("target 1");
	fragy.attack("target 1");
	
	std::cout << std::endl;

	clapy.takeDamage(10);
	scavy.takeDamage(10);
	fragy.takeDamage(10);

	std::cout << std::endl;

	clapy.attack("target 2");
	scavy.attack("target 2");
	fragy.attack("target 2");

	std::cout << std::endl;

	clapy.takeDamage(50);
	scavy.takeDamage(50);
	fragy.takeDamage(50);

	std::cout << std::endl;

	clapy.attack("target 3");
	scavy.attack("target 3");
	fragy.attack("target 3");

	std::cout << std::endl;

	scavy.guardGate();
	fragy.highFivesGuys();

	std::cout << std::endl;

	
	clapy.takeDamage(50);
	scavy.takeDamage(50);
	fragy.takeDamage(50);

	std::cout << std::endl;

	clapy.attack("target 4");
	scavy.attack("target 4");
	fragy.attack("target 4");

	std::cout << std::endl;

	scavy.guardGate();
	fragy.highFivesGuys();

	std::cout << std::endl;
	
	return 0;
}
