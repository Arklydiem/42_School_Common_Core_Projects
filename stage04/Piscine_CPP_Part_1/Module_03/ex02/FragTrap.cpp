/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:15:39 by argomez           #+#    #+#             */
/*   Updated: 2023/03/22 09:31:30 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap(){
	std::cout << "\e[38;5;208mFragTrap\e[0m Constructor \'Simple\' called." << std::endl << std::endl;
	this->_name = "\e[38;5;208m<none>\e[0m";
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_attackDamage = 30;
	this->__display();
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	std::cout << "\e[38;5;208mFragTrap\e[0m Constructor \'String\' called." << std::endl << std::endl;
	this->_name = "\e[38;5;208m" + name + "\e[0m";
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_attackDamage = 30;
	this->__display();
	return ;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj){
	std::cout << "\e[38;5;208mFragTrap\e[0m Constructor \'by copy\' called." << std::endl << std::endl;
	*this = obj;
	return ;
}

FragTrap &FragTrap::operator=(const FragTrap &obj){
	std::cout << "FragTrap Operator equal called to create a copy of " << obj._name << " on " << this->_name << std::endl << std::endl;
	if (this != &obj){
		this->_name = obj._name;
		this->_hitPoint = obj._hitPoint;
		this->_energyPoint = obj._energyPoint;
		this->_attackDamage = obj._attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap(){
	std::cout << "\e[38;5;208mFragTrap\e[0m Desctructor called for : " << this->_name << std::endl << std::endl;
	return ;
}

void	FragTrap::highFivesGuys(void){
	if (this->_canAct() == false){return;}
	std::cout << "\e[38;5;208mFragTrap\e[0m " << this->_name << " wait lonely to you to highFive with him..." << std::endl << std::endl;
	return ;
}