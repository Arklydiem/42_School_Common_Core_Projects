/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:34:05 by argomez           #+#    #+#             */
/*   Updated: 2023/03/15 13:15:27 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Brain.hpp"

Brain::Brain(){
	std::cout << "\t\e[3mBrain\e[0m \e[92mcreated\e[0m." << std::endl;
	return ;
}

Brain::Brain(const Brain &obj){
	std::cout << "\t\e[3mBrain\e[0m \e[93mcreated by a copy from another\e[0m." << std::endl;
	*this = obj;
	return ;
}

Brain &Brain::operator=(const Brain &obj){
	std::cout << "\t\e[3mBrain\e[0m \e[33mcreated by a assignation from another\e[0m." << std::endl;
	if (this != &obj){
		for (int i = 0; i < 100; i++)
			this->_ideas[i] = obj._ideas[i];
	}
	return *this;
}

Brain::~Brain(){
	std::cout << "\t\e[3mBrain\e[0m \e[91mdestroyed\e[0m." << std::endl;
	return ;
}

void	Brain::setIdea(std::string idea){
	int	i;
	for (i = 0; i < 100; i++)
		if (this->_ideas[i].empty() == true)
			break;
	if (i >= 100)
		i = 99;
	this->_ideas[i] = idea;
}

std::string Brain::getIdea(int index){
	if (index >= 100)
		return NULL;
	return (this->_ideas[index]);
}