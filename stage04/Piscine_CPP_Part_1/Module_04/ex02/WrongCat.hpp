/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:25:16 by argomez           #+#    #+#             */
/*   Updated: 2023/03/15 10:44:12 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		WRONGCAT_HPP
# define	WRONGCAT_HPP

#include "./WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
	public:
		WrongCat ();
		WrongCat (const WrongCat&);
		WrongCat &operator=(const WrongCat&);
		~WrongCat ();
		void	makeSound(void) const;
	protected:
};

#endif