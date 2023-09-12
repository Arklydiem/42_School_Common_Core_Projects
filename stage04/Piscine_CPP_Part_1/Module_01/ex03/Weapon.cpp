/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:30:52 by argomez           #+#    #+#             */
/*   Updated: 2023/01/14 17:30:52 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void){
    return ;
}

Weapon::Weapon(std::string  type): _type(type){
    return ;
}

Weapon::~Weapon(){
    return ;
}

void            Weapon::setType(std::string type){
    this->_type = type;
}

std::string const     Weapon::getType(){
    std::string     typeREF(this->_type);
    return (typeREF);
}
