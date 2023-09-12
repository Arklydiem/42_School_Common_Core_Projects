/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 15:30:24 by argomez           #+#    #+#             */
/*   Updated: 2023/03/13 12:58:32 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SCAVTRAP_HPP
# define	SCAVTRAP_HPP

# include	"./ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
	public:
		ScavTrap ();
		ScavTrap (std::string name);
		ScavTrap (const ScavTrap&);
		ScavTrap &operator=(const ScavTrap&);
		~ScavTrap ();
		void	attack(const std::string &target);
		void	guardGate(void);
	private:
};

#endif