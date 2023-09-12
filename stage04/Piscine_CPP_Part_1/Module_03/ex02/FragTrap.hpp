/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 11:15:33 by argomez           #+#    #+#             */
/*   Updated: 2023/03/13 11:25:42 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		FRAGTRAP_HPP
# define	FRAGTRAP_HPP

# include	"./ClapTrap.hpp"

class FragTrap : public ClapTrap
{
	public:
		FragTrap ();
		FragTrap (std::string name);
		FragTrap (const FragTrap&);
		FragTrap &operator=(const FragTrap&);
		~FragTrap ();
		void	highFivesGuys(void);
	private:
		
};

#endif