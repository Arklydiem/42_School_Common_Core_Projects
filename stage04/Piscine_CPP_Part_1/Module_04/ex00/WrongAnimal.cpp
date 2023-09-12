/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:10:21 by argomez           #+#    #+#             */
/*   Updated: 2023/03/15 11:14:20 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
	std::cout << "WrongAnimal \e[92mcreated\e[0m." << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type){
	std::cout << "WrongAnimal \e[34mcreated with type\e[0m : " << this->_type << "." << std::endl;
	return ;
}

WrongAnimal::WrongAnimal(const WrongAnimal &obj){
	std::cout << "WrongAnimal \e[93mcreated by a copy from another\e[0m." << std::endl;
	*this = obj;
	return ;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &obj){
	std::cout << "WrongAnimal \e[33mcreated by a assignation from another\e[0m." << std::endl;
	if (this != &obj){
		(void)obj;
	}
	return *this;
}

WrongAnimal::~WrongAnimal(){
	std::cout << "WrongAnimal \e[91mdestroyed\e[0m." << std::endl;
	return ;
}

void	WrongAnimal::makeSound(void) const{
	std::cout << "Some inaudible noise" << std::endl;
	return ;
}

std::string	WrongAnimal::getType(void) const{
	return (this->_type);
}