/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:30:30 by argomez           #+#    #+#             */
/*   Updated: 2023/03/22 09:31:08 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(){
	std::cout << "\e[38;5;141mScavTrap\e[0m Constructor \'Simple\' called." << std::endl << std::endl;
	this->_name = "\e[38;5;141m<none>\e[0m";
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 20;
	this->__display();
	return ;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name){
	std::cout << "\e[38;5;141mScavTrap\e[0m Constructor \'String\' called." << std::endl << std::endl;
	this->_name = "\e[38;5;141m" + name + "\e[0m";
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 20;
	this->__display();
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj){
	std::cout << "\e[38;5;141mScavTrap\e[0m Constructor \'by copy\' called." << std::endl << std::endl;
	*this = obj; 
	return ;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj){
	std::cout << "\e[38;5;141mScavTrap\e[0m Operator equal called to create a copy of " << obj._name << " on " << this->_name << std::endl << std::endl;
	if (this != &obj){
		this->_name = obj._name;
		this->_hitPoint = obj._hitPoint;
		this->_energyPoint = obj._energyPoint;
		this->_attackDamage = obj._attackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap(){
	std::cout << "\e[38;5;141mScavTrap\e[0m Desctructor called for : " << this->_name << std::endl << std::endl;
	return ;
}

void	ScavTrap::attack(const std::string &target){
	if (this->_canAct() == false){return;}
	std::cout << "\e[38;5;141mScavTrap\e[0m " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl << std::endl;
	this->_energyPoint--;
}

void	ScavTrap::guardGate(){
	if (this->_canAct() == false){return;}
	std::cout << "\e[38;5;141mScavTrap\e[0m " << this->_name << " entered in gate keeper mode" << std::endl << std::endl;
	return ;
}
