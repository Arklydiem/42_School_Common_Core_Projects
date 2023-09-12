/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:31:31 by argomez           #+#    #+#             */
/*   Updated: 2023/01/14 17:31:31 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     HUMANB_HPP
# define    HUMANB_HPP

#include "Weapon.hpp"

class HumanB
{
    private:
        std::string _name;
        Weapon      *_weapon;
    public:
        HumanB(std::string name);
        ~HumanB(void);
        void    setWeapon(Weapon &weapon);
        void    attack(void);
};

#endif
