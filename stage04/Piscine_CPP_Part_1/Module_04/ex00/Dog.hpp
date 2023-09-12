/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 10:45:03 by argomez           #+#    #+#             */
/*   Updated: 2023/03/22 17:32:01 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		DOG_HPP
# define	DOG_HPP

#include "./Animal.hpp"

class Dog : virtual public Animal
{
	public:
		Dog ();
		Dog (const Dog&);
		Dog &operator=(const Dog&);
		~Dog ();
		void	makeSound(void) const;
	private:
		
};

#endif