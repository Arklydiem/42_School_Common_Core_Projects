/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:25:48 by argomez           #+#    #+#             */
/*   Updated: 2023/03/24 11:47:50 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./Cat.hpp"

Cat::Cat() : AAnimal("Cat"){
	std::cout << "\e[4mCat\e[0m \e[92mcreated\e[0m." << std::endl;
	this->_brain = new Brain;
	return ;
}

Cat::Cat(const Cat &obj) : AAnimal(obj){
	std::cout << "\e[4mCat\e[0m \e[93mcreated by a copy from another\e[0m." << std::endl;
	this->_brain = NULL;
	*this = obj;
	return ;
}

Cat &Cat::operator=(const Cat &obj){
	std::cout << "\e[4mCat\e[0m \e[33mcreated by a assignation from another\e[0m." << std::endl;
	if (this != &obj){
		this->_type = obj._type;
		if (this->_brain)
			delete this->_brain;
		this->_brain = new Brain;
		*this->_brain = *obj._brain;
	}
	return *this;
}

Cat::~Cat(){
	std::cout << "\e[4mCat\e[0m \e[91mdestroyed\e[0m." << std::endl;
	if (this->_brain)
		delete this->_brain;
	return ;
}

void	Cat::makeSound(void) const{
	std::cout << "Meow" << std::endl;
	return ;
}

void Cat::showBrain(int index) const{
	for (int i = 0; i < index; i++)
	{
		if (i >= 100 || this->_brain->getIdea(i).empty())
			break;
		std::cout << this->_brain->getIdea(i) << std::endl;
	}
}

Brain*	Cat::getBrain()const {
	return this->_brain;
}
