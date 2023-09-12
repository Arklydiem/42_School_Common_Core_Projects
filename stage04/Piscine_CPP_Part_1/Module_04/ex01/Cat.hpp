/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:25:16 by argomez           #+#    #+#             */
/*   Updated: 2023/03/22 17:46:09 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		CAT_HPP
# define	CAT_HPP

#include "./Animal.hpp"
#include "./Brain.hpp"

class Cat : virtual public Animal
{
	public:
		Cat ();
		Cat (const Cat&);
		Cat &operator=(const Cat&);
		~Cat ();
		void	makeSound(void) const;
		void	showBrain(int index) const ;
		Brain*	getBrain() const;
	private:
		Brain *_brain;
};

#endif