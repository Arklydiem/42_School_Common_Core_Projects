/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:48:54 by argomez           #+#    #+#             */
/*   Updated: 2023/03/13 12:48:57 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./DiamondTrap.hpp"

DiamondTrap::DiamondTrap(){
	return ;
}

DiamondTrap::DiamondTrap(const DiamondTrap &obj){
	*this = obj;
	return ;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &obj){
	if (this != &obj){
		(void)obj;
	}
	return *this;
}

DiamondTrap::~DiamondTrap(){
	return ;
}
