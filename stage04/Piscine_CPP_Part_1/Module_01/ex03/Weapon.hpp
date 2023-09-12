/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:25:38 by argomez           #+#    #+#             */
/*   Updated: 2023/01/14 17:25:38 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     WEAPON_HPP
# define    WEAPON_HPP

#include <iostream>

class Weapon
{
    private:
        std::string _type;
    public:
        Weapon(void);
        Weapon(std::string type);
        ~Weapon(void);

        std::string const	getType(void);
        void            	setType(std::string type);
};

#endif
