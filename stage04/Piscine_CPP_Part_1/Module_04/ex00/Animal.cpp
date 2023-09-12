/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:10:21 by argomez           #+#    #+#             */
/*   Updated: 2023/03/22 17:32:01 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Animal.hpp"

Animal::Animal(){
	std::cout << "Animal \e[92mcreated\e[0m." << std::endl;
	return ;
}

Animal::Animal(std::string type) : _type(type){
	std::cout << "Animal \e[34mcreated with type\e[0m : " << this->_type << "." << std::endl;
	return ;
}

Animal::Animal(const Animal &obj){
	std::cout << "Animal \e[93mcreated by a copy from another\e[0m." << std::endl;
	*this = obj;
	return ;
}

Animal &Animal::operator=(const Animal &obj){
	std::cout << "Animal \e[33mcreated by a assignation from another\e[0m." << std::endl;
	if (this != &obj){
		this->_type = obj._type;
	}
	return *this;
}

Animal::~Animal(){
	std::cout << "Animal \e[91mdestroyed\e[0m." << std::endl;
	return ;
}

void	Animal::makeSound(void) const{
	std::cout << "Some inaudible noise" << std::endl;
	return ;
}

std::string	Animal::getType(void) const{
	return (this->_type);
}