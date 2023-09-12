/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:24:20 by argomez           #+#    #+#             */
/*   Updated: 2023/03/01 13:39:01 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Harl.hpp"

Harl::Harl(void){
	return ;
}

Harl::~Harl(void){
	return ;
}

void	Harl::debug(void){
	std::cout  << "[DEBUG]" << std::endl << "There is some debug informations"
		<< std::endl << std::endl;
}

void	Harl::info(void){
	std::cout << "[INFO]" << std::endl << "There is some detailed informations"
		<< std::endl << std::endl;
}

void	Harl::warning(void){
	std::cout << "[WARNING]" << std::endl << "There is a non critical problem"
		<< std::endl << std::endl;
}

void	Harl::error(void){
	std::cout << "[ERROR]" << std::endl << "There is a critical problem"
		<< std::endl << std::endl;
}

void	Harl::complain(std::string level){
	std::string levels[5];
	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";

	int	index = 0;
	while (!levels[index].empty() && levels[index].compare(level))
		index++;
	
	switch (index)
	{
		case 0:
			this->debug();
			__attribute__((fallthrough));
		case 1:
			this->info();
			__attribute__((fallthrough));
		case 2:
			this->warning();
			__attribute__((fallthrough));
		case 3:
			this->error();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}