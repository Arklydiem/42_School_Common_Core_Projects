/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:08:58 by argomez           #+#    #+#             */
/*   Updated: 2023/03/22 09:46:24 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ClapTrap.hpp"

ClapTrap::ClapTrap(void): _name("\e[38;5;41m<none>\e[0m"), _hitPoint(10), _energyPoint(10), _attackDamage(0){
	std::cout << "\e[38;5;41mClapTrap\e[0m Constructor \'Simple\' called." << std::endl << std::endl;
	this->__display();
	return ;
}

ClapTrap::ClapTrap(std::string name):  _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0){
	std::cout << "\e[38;5;41mClapTrap\e[0m Constructor \'String\' called." << std::endl << std::endl;
	this->_name = "\e[38;5;41m" + name + "\e[0m";
	this->__display();
	return ;
}

ClapTrap::ClapTrap(const ClapTrap &obj){
	std::cout << "\e[38;5;41mClapTrap\e[0m Constructor \'by copy\' called." << std::endl << std::endl;
	*this = obj;
	return ;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &obj){
	std::cout << "\e[38;5;41mClapTrap\e[0m Operator equal called to create a copy of " << obj._name << " on " << this->_name << std::endl << std::endl;
	if (this != &obj){
		this->_name = obj._name;
		this->_hitPoint = obj._hitPoint;
		this->_energyPoint = obj._energyPoint;
		this->_attackDamage = obj._attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap(){
	std::cout << "\e[38;5;41mClapTrap\e[0m Desctructor called for : " << this->_name << std::endl << std::endl;
	return ;
}

void	ClapTrap::attack(const std::string &target){
	if (this->_canAct() == false){return;}
	std::cout << "\e[38;5;41mClapTrap\e[0m " << this->_name << " attacks " << target << ", causing " << this->_attackDamage << " points of damage !" << std::endl;
	this->_energyPoint--;
}

void	ClapTrap::takeDamage(unsigned int amount){
	std::cout << "\e[38;5;41mClapTrap\e[0m " << this->_name << " lose " << amount << " hitPoint !" << std::endl;
	this->_hitPoint -= amount;
}

void	ClapTrap::beRepaired(unsigned int amount){
	if (this->_canAct() == false){return;}
	std::cout << "\e[38;5;41mClapTrap\e[0m " << this->_name << " repaired " << amount << " hitPoint !" << std::endl;
	this->_energyPoint--;
	this->_hitPoint += amount;
}

void	ClapTrap::__display(void){
	std::cout << std::left << std::setw(15) << "_name" << "\e[1;36m ➔ \e[0;0m" << this->_name << std::endl;
	std::cout << std::left << std::setw(15) << "_hitPoint" << "\e[1;36m ➔ \e[0;0m" << this->_hitPoint << std::endl;
	std::cout << std::left << std::setw(15) << "_energyPoint" << "\e[1;36m ➔ \e[0;0m" << this->_energyPoint << std::endl;
	std::cout << std::left << std::setw(15) << "_attackDamage" << "\e[1;36m ➔ \e[0;0m" << this->_attackDamage << std::endl;
	std::cout << std::endl;
}

bool	ClapTrap::_canAct(void){
	if (this->_energyPoint <= 0 && this->_hitPoint <= 0){
		std::cout << this->_name << " has not enough Energy and Hit point to make an action." << std::endl;
		return false;
	}
	else if (this->_energyPoint <= 0){
		std::cout << this->_name << " has not enough Energy to make an action." << std::endl;
		return false;
	}
	else if (this->_hitPoint <= 0){
		std::cout << this->_name << " has not enough Hit point to make an action." << std::endl;
		return false;
	}
	return true;
}