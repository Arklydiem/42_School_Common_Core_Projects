/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 10:23:29 by argomez           #+#    #+#             */
/*   Updated: 2023/01/14 10:23:29 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ZOMBIE_HPP
# define	ZOBIE_HPP

#include <iostream>
#include <string>

class Zombie
{
    private:
       std::string _name;
    public:
        Zombie(std::string name);
        ~Zombie(void);
        void    announce( void );
};

Zombie* newZombie( std::string name );
void    randomChump( std::string name );

#endif
