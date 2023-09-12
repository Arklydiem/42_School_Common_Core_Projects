/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:30:30 by argomez           #+#    #+#             */
/*   Updated: 2023/03/13 12:29:41 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ScavTrap.hpp"

ScavTrap::ScavTrap(){
	std::cout << "ScavTrap created." << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name){
	std::cout << "ScavTrap created from a ClapTrap :" << std::endl;
	this->_hitPoint = 100;
	this->_energyPoint = 50;
	this->_attackDamage = 20;
	std::cout << std::left << std::setw(15) << "_name" << "\e[1;36m ➔ \e[0;0m" << this->_name << std::endl;
	std::cout << std::left << std::setw(15) << "_hitPoint" << "\e[1;36m ➔ \e[0;0m" << this->_hitPoint << std::endl;
	std::cout << std::left << std::setw(15) << "_energyPoint" << "\e[1;36m ➔ \e[0;0m" << this->_energyPoint << std::endl;
	std::cout << std::left << std::setw(15) << "_attackDamage" << "\e[1;36m ➔ \e[0;0m" << this->_attackDamage << std::endl;
	std::cout << std::endl;
	return ;
	return ;
}

ScavTrap::ScavTrap(const ScavTrap &obj) : ClapTrap(obj){
	std::cout << "ScavTrap Constructor copy called to create a copy of " << obj._name << std::endl;
	*this = obj;
	return ;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &obj){
	std::cout << "ScavTrap Operator equal called to create a copy of " << obj._name << std::endl;
	if (this != &obj){
		this->_name = obj._name;
		this->_hitPoint = obj._hitPoint;
		this->_energyPoint = obj._energyPoint;
		this->_attackDamage = obj._attackDamage;
	}
	return *this;
}

ScavTrap::~ScavTrap(){
	std::cout << "ScavTrap deleted : \e[31m" << this->_name << "\e[0m" << std::endl;
	return ;
}

void	ScavTrap::attack(const std::string &target){
	if (this->_energyPoint <= 0 || this->_hitPoint <= 0){
		std::cout << "\e[31m" << (this->_name.empty() ? "<none>" : this->_name) << "\e[0m has not enough Energy or Hit point" << std::endl;
		return ;
	}
	std::cout << "ScavTrap \e[31m" << (this->_name.empty() ? "<none>" : this->_name) << "\e[0m attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoint--;
}

void	ScavTrap::guardGate(){
	if (this->_energyPoint <= 0 || this->_hitPoint <= 0){
		std::cout << "\e[31m" << (this->_name.empty() ? "<none>" : this->_name) << "\e[0m has not enough Energy or Hit point" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " entered in gate keeper mode" << std::endl;
	return ;
}