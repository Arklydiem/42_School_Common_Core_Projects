/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:45:03 by argomez           #+#    #+#             */
/*   Updated: 2023/03/22 17:55:41 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		DOG_HPP
# define	DOG_HPP

#include "./AAnimal.hpp"
#include "./Brain.hpp"

class Dog : virtual public AAnimal
{
	public:
		Dog ();
		Dog (const Dog&);
		Dog &operator=(const Dog&);
		~Dog ();
		void	makeSound(void) const;
		void	showBrain(int index) const;
		Brain*	getBrain()const ;
	private:
		Brain *_brain;
};

#endif