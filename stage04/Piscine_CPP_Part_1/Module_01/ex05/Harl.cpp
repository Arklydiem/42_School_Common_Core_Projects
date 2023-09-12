/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 13:24:20 by argomez           #+#    #+#             */
/*   Updated: 2023/03/06 17:34:52 by argomez          ###   ########.fr       */
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
	std::cout << "[DEBUG] there is some debug informations"
		<< std::endl;
}

void	Harl::info(void){
	std::cout << "[INFO] there is some detailed informations"
		<< std::endl;
}

void	Harl::warning(void){
	std::cout << "[WARNING] there is a non critical problem"
		<< std::endl;
}

void	Harl::error(void){
	std::cout << "[ERROR] there is a critical problem"
		<< std::endl;
}

void	Harl::complain(std::string level){
	f_ptr_tab[0] = &Harl::debug;
	f_ptr_tab[1] = &Harl::info;
	f_ptr_tab[2] = &Harl::warning;
	f_ptr_tab[3] = &Harl::error;

	std::string levels[5];
	levels[0] = "DEBUG";
	levels[1] = "INFO";
	levels[2] = "WARNING";
	levels[3] = "ERROR";

	int	index = 0;
	while (!levels[index].empty() && level != levels[index])
		index++;
	if (index <= 3)
		(this->*f_ptr_tab[index])();
}