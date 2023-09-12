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
    Zombie* horde = zombieHorde(10, "test");

    for (size_t i = 0; i < 10; i++)
        horde[i].announce();
	
    delete [] horde; 
	return (0);
}
