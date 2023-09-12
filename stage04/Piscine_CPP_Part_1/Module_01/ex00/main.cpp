/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:33:49 by argomez           #+#    #+#             */
/*   Updated: 2023/01/14 10:33:49 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void){
    Zombie  zombie_1 = Zombie("zombie_1");
    Zombie* zombie_2 = newZombie("zombie_2");

    zombie_1.announce();
    zombie_2->announce();

    randomChump("zombie_3");
    randomChump("zombie_4");

    delete zombie_2;
	return (0);
}