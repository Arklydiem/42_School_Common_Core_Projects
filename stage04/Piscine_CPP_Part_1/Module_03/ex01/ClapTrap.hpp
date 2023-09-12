/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 10:08:51 by argomez           #+#    #+#             */
/*   Updated: 2023/03/22 09:17:11 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		CLAPTRAP_HPP
# define	CLAPTRAP_HPP

# include	<string>
# include	<iostream>
# include	<iomanip>

class ClapTrap
{
	public:
		ClapTrap (void);
		ClapTrap (std::string name);
		ClapTrap (const ClapTrap&);
		ClapTrap &operator=(const ClapTrap&);
		~ClapTrap ();
		void	attack(const std::string &target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
		void	__display(void);
	protected:
		std::string _name;
		int			_hitPoint;
		int			_energyPoint;
		int			_attackDamage;
		bool		_canAct(void);

};

#endif