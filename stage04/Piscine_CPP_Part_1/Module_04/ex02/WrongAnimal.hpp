/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:10:28 by argomez           #+#    #+#             */
/*   Updated: 2023/03/15 10:55:04 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		WRONGANIMAL_HPP
# define	WRONGANIMAL_HPP

#include	<iostream>
#include	<string>

class WrongAnimal
{
	public:
		WrongAnimal ();
		WrongAnimal (std::string type);
		WrongAnimal (const WrongAnimal&);
		WrongAnimal &operator=(const WrongAnimal&);
		~WrongAnimal ();
		void		makeSound(void) const;
		std::string			getType(void) const;
	protected:
		std::string _type;
};

#endif