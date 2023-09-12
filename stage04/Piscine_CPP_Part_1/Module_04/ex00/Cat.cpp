/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:25:48 by argomez           #+#    #+#             */
/*   Updated: 2023/03/22 17:32:01 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Cat.hpp"

Cat::Cat() : Animal("Cat"){
	std::cout << "\e[4mCat\e[0m \e[92mcreated\e[0m." << std::endl;
	return ;
}

Cat::Cat(const Cat &obj) : Animal(obj){
	std::cout << "\e[4mCat\e[0m \e[93mcreated by a copy from another\e[0m." << std::endl;
	*this = obj;
	return ;
}

Cat &Cat::operator=(const Cat &obj){
	std::cout << "\e[4mCat\e[0m \e[33mcreated by a assignation from another\e[0m." << std::endl;
	if (this != &obj){
		this->_type = obj._type;
	}
	return *this;
}

Cat::~Cat(){
	std::cout << "\e[4mCat\e[0m \e[91mdestroyed\e[0m." << std::endl;
	return ;
}

void	Cat::makeSound(void) const{
	std::cout << "Meow" << std::endl;
	return ;
}