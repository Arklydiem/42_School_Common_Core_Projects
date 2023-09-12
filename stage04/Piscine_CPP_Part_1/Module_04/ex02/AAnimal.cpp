/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:10:21 by argomez           #+#    #+#             */
/*   Updated: 2023/03/22 15:50:03 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./AAnimal.hpp"

AAnimal::AAnimal(){
	std::cout << "Animal \e[92mcreated\e[0m." << std::endl;
	return ;
}

AAnimal::AAnimal(std::string type) : _type(type){
	std::cout << "Animal \e[34mcreated with type\e[0m : " << this->_type << "." << std::endl;
	return ;
}

AAnimal::AAnimal(const AAnimal &obj){
	std::cout << "Animal \e[93mcreated by a copy from another\e[0m." << std::endl;
	*this = obj;
	return ;
}

AAnimal &AAnimal::operator=(const AAnimal &obj){
	std::cout << "Animal \e[33mcreated by a assignation from another\e[0m." << std::endl;
	if (this != &obj){
		this->_type = obj._type;
	}
	return *this;
}

AAnimal::~AAnimal(){
	std::cout << "Animal \e[91mdestroyed\e[0m." << std::endl;
	return ;
}

std::string	AAnimal::getType(void) const{
	return (this->_type);
}

