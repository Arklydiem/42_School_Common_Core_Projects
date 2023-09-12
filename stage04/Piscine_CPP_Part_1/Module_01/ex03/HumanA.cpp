/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:30:33 by argomez           #+#    #+#             */
/*   Updated: 2023/01/14 17:30:33 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon){
    return ;
}

HumanA::~HumanA(){
	return ;
}

void    HumanA::attack(void){
    std::cout   << this->_name << " attacks with their " << this->_weapon.getType()
                << std::endl;
}