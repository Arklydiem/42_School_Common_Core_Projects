/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:34:35 by argomez           #+#    #+#             */
/*   Updated: 2023/03/22 09:51:44 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"./ClapTrap.hpp"

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
	return 0;
}
