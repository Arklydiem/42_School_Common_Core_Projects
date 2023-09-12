/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 17:31:05 by argomez           #+#    #+#             */
/*   Updated: 2023/01/14 17:31:05 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     HUMANA_HPP
# define    HUMANA_HPP

#include "Weapon.hpp"

class HumanA
{
    private:
        std::string _name;
        Weapon      &_weapon;
    public:
        HumanA(std::string name, Weapon &weapon);
        ~HumanA(void);
        void    attack(void);
};

#endif
