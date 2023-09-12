/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:10:28 by argomez           #+#    #+#             */
/*   Updated: 2023/03/22 17:32:01 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ANIMAL_HPP
# define	ANIMAL_HPP

#include	<iostream>
#include	<string>

class Animal
{
	public:
		Animal ();
		Animal (std::string type);
		Animal (const Animal&);
		Animal &operator=(const Animal&);
		virtual ~Animal ();
		virtual void		makeSound(void) const;
		std::string			getType(void) const;
	protected:
		std::string _type;
};

#endif