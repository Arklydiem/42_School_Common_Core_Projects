/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:08:58 by argomez           #+#    #+#             */
/*   Updated: 2023/03/13 12:21:56 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"

ClapTrap::ClapTrap(void): _hitPoint(10), _energyPoint(10), _attackDamage(0){ 
	return ;
}

ClapTrap::ClapTrap(std::string name):  _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0){
	std::cout << "Constructor called to create : " << std::endl;
	std::cout << std::left << std::setw(15) << "_name" << "\e[1;36m ➔ \e[0;0m" << "\e[31m" << this->_name << "\e[0m" << std::endl;
	std::cout << std::left << std::setw(15) << "_hitPoint" << "\e[1;36m ➔ \e[0;0m" << this->_hitPoint << std::endl;
	std::cout << std::left << std::setw(15) << "_energyPoint" << "\e[1;36m ➔ \e[0;0m" << this->_energyPoint << std::endl;
	std::cout << std::left << std::setw(15) << "_attackDamage" << "\e[1;36m ➔ \e[0;0m" << this->_attackDamage << std::endl;
	std::cout << std::endl;
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &obj){
	std::cout << "Constructor copy called to create a copy of " << obj._name << std::endl;
	*this = obj;
	return ;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj){
	std::cout << "Operator equal called to create a copy of " << obj._name << std::endl;
	if (this != &obj){
		this->_name = obj._name;
		this->_hitPoint = obj._hitPoint;
		this->_energyPoint = obj._energyPoint;
		this->_attackDamage = obj._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap(){
	std::cout << "Desctructor called for : " << "\e[31m" << this->_name << "\e[0m" << std::endl;
	return ;
}

void	ClapTrap::attack(const std::string &target){
	if (this->_energyPoint <= 0 || this->_hitPoint <= 0){
		std::cout << "\e[31m" << (this->_name.empty() ? "<none>" : this->_name) << "\e[0m has not enough Energy or Hit point" << std::endl;
		return ;
	}
	std::cout << "ClapTrap \e[31m" << (this->_name.empty() ? "<none>" : this->_name) << "\e[0m attacks " << target << ", causing " << this->_attackDamage << " points of damage!" << std::endl;
	this->_energyPoint--;
}

void	ClapTrap::takeDamage(unsigned int amount){
	std::cout << "ClapTrap \e[31m" << (this->_name.empty() ? "<none>" : this->_name) << "\e[0m lose " << amount << " hitPoint !" << std::endl;
	this->_hitPoint -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (this->_energyPoint <= 0 || this->_hitPoint <= 0){
		std::cout << "\e[31m" << _name << "\e[0m has not enough Energy or Hit point" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << (this->_name.empty() ? "<none>" : this->_name) << " repaired " << amount << " hitPoint !" << std::endl;
	this->_energyPoint--;
	this->_hitPoint += amount;
}
