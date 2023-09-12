/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:10:28 by argomez           #+#    #+#             */
/*   Updated: 2023/03/22 15:50:03 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		AANIMAL_HPP
# define	AANIMAL_HPP

#include	<iostream>
#include	<string>
#include	"./Brain.hpp"

class AAnimal
{
	public:
		AAnimal ();
		AAnimal (std::string type);
		AAnimal (const AAnimal&);
		AAnimal &operator=(const AAnimal&);
		virtual ~AAnimal ();
		virtual void		makeSound(void) const = 0;
		virtual std::string	getType(void) const;
		virtual void		showBrain(int index) const = 0;
		virtual Brain		*getBrain()const = 0;
	protected:
		std::string _type;
};

#endif