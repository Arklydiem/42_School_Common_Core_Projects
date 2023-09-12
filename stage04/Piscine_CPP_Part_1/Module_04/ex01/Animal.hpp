/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:10:28 by argomez           #+#    #+#             */
/*   Updated: 2023/03/23 10:29:26 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ANIMAL_HPP
# define	ANIMAL_HPP

#include	<iostream>
#include	<string>
#include	"./Brain.hpp"

class Animal
{
	public:
		Animal ();
		Animal (std::string type);
		Animal (const Animal&);
		Animal &operator=(const Animal&);
		virtual ~Animal ();
		virtual void		makeSound(void) const;
		virtual std::string	getType(void) const;
		virtual void		showBrain(int index) const;
		virtual	Brain*		getBrain() const = 0;
	protected:
		std::string _type;
};

#endif