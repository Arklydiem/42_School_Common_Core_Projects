/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:34:35 by argomez           #+#    #+#             */
/*   Updated: 2023/03/22 09:51:11 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"./ClapTrap.hpp"
#include	"./ScavTrap.hpp"
#include	"./FragTrap.hpp"

int main(void)
{
	{
		ClapTrap	clapy("clapy");
		clapy.attack("target 1");
		ClapTrap	clapy_copy(clapy);
		clapy.takeDamage(5);
		ClapTrap	clapy_assign;
		clapy_assign = clapy;
		clapy_assign.__display();
		clapy.beRepaired(984);
		ClapTrap	clapy_erased("clapy_erased");
		clapy_erased = clapy;
		clapy_erased.__display();
		for (int i = 0; i < 10; i++)
			clapy.attack("target 2");
		std::cout << "<-------------------- Then got -------------------->" << std::endl;
		clapy.__display();
		clapy_copy.__display();
		clapy_assign.__display();
		clapy_erased.__display();
	}
	std::cout << std::endl;
	{
		ScavTrap	scavy("scavy");
		scavy.attack("target 1");
		ScavTrap	scavy_copy(scavy);
		scavy.takeDamage(43);
		ScavTrap	scavy_assign;
		scavy_assign = scavy;
		scavy_assign.__display();
		scavy.beRepaired(64);
		ScavTrap	scavy_erased("scavy_erased");
		scavy_erased = scavy;
		scavy_erased.guardGate();
		scavy_erased.__display();
		for (int i = 0; i < 50; i++)
			scavy.attack("target 2");
		std::cout << "<-------------------- Then got -------------------->" << std::endl;
		scavy.__display();
		scavy_copy.__display();
		scavy_assign.__display();
		scavy_erased.__display();
	}
	std::cout << std::endl;
	{
		FragTrap	fragy("fragy");
		fragy.attack("target 1");
		FragTrap	fragy_copy(fragy);
		fragy.takeDamage(97);
		FragTrap	fragy_assign;
		fragy_assign = fragy;
		fragy_assign.__display();
		fragy.beRepaired(5646);
		FragTrap	fragy_erased("fragy_erased");
		fragy_erased = fragy;
		fragy_erased.highFivesGuys();
		fragy_erased.__display();
		for (int i = 0; i < 100; i++)
			fragy.attack("target 2");
		std::cout << "<-------------------- Then got -------------------->" << std::endl;
		fragy.__display();
		fragy_copy.__display();
		fragy_assign.__display();
		fragy_erased.__display();
	}
	return 0;
}
