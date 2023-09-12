/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:45:25 by argomez           #+#    #+#             */
/*   Updated: 2023/03/22 17:32:01 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Dog.hpp"

Dog::Dog() : Animal("Dog"){
	std::cout << "\e[4mDog\e[0m \e[92mcreated\e[0m." << std::endl;
	return ;
}

Dog::Dog(const Dog &obj) : Animal(obj){
	std::cout << "\e[4mDog\e[0m \e[93mcreated by a copy from another\e[0m." << std::endl;
	*this = obj;
	return ;
}

Dog &Dog::operator=(const Dog &obj){
	std::cout << "\e[4mDog\e[0m \e[33mcreated by a assignation from another\e[0m." << std::endl;
	if (this != &obj){
		this->_type = obj._type;
	}
	return *this;
}

Dog::~Dog(){
	std::cout << "\e[4mDog\e[0m \e[91mdestroyed\e[0m." << std::endl;
	return ;
}

void	Dog::makeSound(void) const{
	std::cout << "Woof" << std::endl;
	return ;
}