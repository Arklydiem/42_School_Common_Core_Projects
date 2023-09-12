/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:48:44 by argomez           #+#    #+#             */
/*   Updated: 2023/03/17 13:53:21 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		DIAMONDTRAP_HPP
# define	DIAMONDTRAP_HPP

#include "./ScavTrap.hpp"
#include "./FragTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
	public:
		DiamondTrap ();
		DiamondTrap (const DiamondTrap&);
		DiamondTrap &operator=(const DiamondTrap&);
		~DiamondTrap ();
	private:
		
};

#endif