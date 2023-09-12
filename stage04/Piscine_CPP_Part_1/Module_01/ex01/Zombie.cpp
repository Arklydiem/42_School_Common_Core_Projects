/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:21:20 by argomez           #+#    #+#             */
/*   Updated: 2023/01/14 10:21:20 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void) {
    return ;
}

Zombie::Zombie(std::string name): _name(name){
    return ;
}

Zombie::~Zombie(){
    std::cout   << "And I will stretch out my hand, and smite "
                << this->_name << std::endl;
    return ;
}

void    Zombie::announce(void){
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void    Zombie::setName(std::string name){
    this->_name = name;
}

