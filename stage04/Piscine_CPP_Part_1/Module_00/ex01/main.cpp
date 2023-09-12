/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:49:54 by argomez           #+#    #+#             */
/*   Updated: 2023/01/12 13:47:36 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.hpp"

int	main(void){
	PhoneBook	repertory;
	std::string command;
	int			index = 0;

	std::cout << std::endl << "📔 Welcome to your PhoneBook" << std::endl << std::endl;
	do
	{
		std::cout << "Here are your commands : ⚙️  [ \e[0;32mADD\e[0;0m | \e[0;33mSEARCH\e[0;0m | \e[0;31mEXIT\e[0;0m ] ⚙️" << std::endl;
		std::cout << "\e[1;5;36m ➔ \e[0;0m";
		command.clear();
		std::getline(std::cin, command);
		if (std::cin.eof())
			break ;
		if (!command.compare("ADD"))
			repertory.add();
		if (std::cin.eof())
			break ;
 		if (!command.compare("SEARCH"))
		{
			command.clear();
			repertory.displayRepertory();
			std::cout << "Contact to display [insert index] : ";
			std::getline(std::cin, command);
			if (std::cin.eof())
				break ;
			if (command.length() == 1 && isdigit(command[0]))
				index = std::atoi(command.c_str());
			if (command.length() >= 2 || !isdigit(command[0]) || index > 7)
				std::cout << "\e[1;33m~ERROR~\e[0m Bad input" << std::endl;
			else
				repertory.search(index);
		}
		std::cout << std::endl;
	} while (!(!command.compare("EXIT") && !command.empty()));

	std::cout << std::endl << "Your PhoneBook gonna be deleted, bye. 🗑" << std::endl;
	
	return (0);
}