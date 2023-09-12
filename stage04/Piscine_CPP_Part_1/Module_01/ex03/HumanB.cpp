/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:31:19 by argomez           #+#    #+#             */
/*   Updated: 2023/01/14 17:31:19 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string name): _name(name){
	this->_weapon = NULL;
    return ;
}

HumanB::~HumanB(){
	return ;
}

void    HumanB::setWeapon(Weapon &weapon){
    this->_weapon = &weapon;
}

void    HumanB::attack(void){
	if (this->_weapon == NULL){
		std::cout << this->_name << " can't attack without weapon, he only do nat 1 on dices..." << std::endl;
		return ;
	}
    std::cout   << this->_name << " attacks with their " << this->_weapon->getType()
                << std::endl;
}
