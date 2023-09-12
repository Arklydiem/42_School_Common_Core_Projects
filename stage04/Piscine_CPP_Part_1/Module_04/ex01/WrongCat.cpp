/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:25:48 by argomez           #+#    #+#             */
/*   Updated: 2023/03/15 10:52:42 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat"){
	std::cout << "\e[4mWrongCat\e[0m \e[92mcreated\e[0m." << std::endl;
	return ;
}

WrongCat::WrongCat(const WrongCat &obj) : WrongAnimal(obj){
	std::cout << "\e[4mWrongCat\e[0m \e[93mcreated by a copy from another\e[0m." << std::endl;
	*this = obj;
	return ;
}

WrongCat &WrongCat::operator=(const WrongCat &obj){
	std::cout << "\e[4mWrongCat\e[0m \e[33mcreated by a assignation from another\e[0m." << std::endl;
	if (this != &obj){
		this->_type = obj._type;
	}
	return *this;
}

WrongCat::~WrongCat(){
	std::cout << "\e[4mWrongCat\e[0m \e[91mdestroyed\e[0m." << std::endl;
	return ;
}

void	WrongCat::makeSound(void) const{
	std::cout << "Meow" << std::endl;
	return ;
}