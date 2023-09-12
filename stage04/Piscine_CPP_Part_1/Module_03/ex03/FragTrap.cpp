/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:15:39 by argomez           #+#    #+#             */
/*   Updated: 2023/03/13 12:31:13 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./FragTrap.hpp"

FragTrap::FragTrap(){
	std::cout << "FragTrap created." << std::endl;
	return ;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
	std::cout << "FragTrap created from a ClapTrap :" << std::endl;
	this->_hitPoint = 100;
	this->_energyPoint = 100;
	this->_attackDamage = 30;
	std::cout << std::left << std::setw(15) << "_name" << "\e[1;36m ➔ \e[0;0m" << "\e[31m" << this->_name << "\e[0m" << std::endl;
	std::cout << std::left << std::setw(15) << "_hitPoint" << "\e[1;36m ➔ \e[0;0m" << this->_hitPoint << std::endl;
	std::cout << std::left << std::setw(15) << "_energyPoint" << "\e[1;36m ➔ \e[0;0m" << this->_energyPoint << std::endl;
	std::cout << std::left << std::setw(15) << "_attackDamage" << "\e[1;36m ➔ \e[0;0m" << this->_attackDamage << std::endl;
	std::cout << std::endl;
	return ;
	return ;
}

FragTrap::FragTrap(const FragTrap &obj) : ClapTrap(obj){
	std::cout << "FragTrap Constructor copy called to create a copy of " << obj._name << std::endl;
	*this = obj;
	return ;
}

FragTrap &FragTrap::operator=(const FragTrap &obj){
	std::cout << "FragTrap Operator equal called to create a copy of " << obj._name << std::endl;
	if (this != &obj){
		this->_name = obj._name;
		this->_hitPoint = obj._hitPoint;
		this->_energyPoint = obj._energyPoint;
		this->_attackDamage = obj._attackDamage;
	}
	return *this;
}

FragTrap::~FragTrap(){
	std::cout << "FragTrap deleted : " << "\e[31m" << this->_name << "\e[0m" << std::endl;
	return ;
}

void	FragTrap::highFivesGuys(void){
	if (this->_energyPoint <= 0 || this->_hitPoint <= 0){
		std::cout << "\e[31m" << _name << "\e[0m has not enough Energy or Hit point" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << "\e[31m" << this->_name << "\e[0m" << " entered in gate keeper mode" << std::endl;
	return ;
}