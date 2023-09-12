/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 13:25:16 by argomez           #+#    #+#             */
/*   Updated: 2023/03/22 17:32:01 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		CAT_HPP
# define	CAT_HPP

#include "./Animal.hpp"

class Cat : virtual public Animal
{
	public:
		Cat ();
		Cat (const Cat&);
		Cat &operator=(const Cat&);
		~Cat ();
		void	makeSound(void) const;
	protected:
};

#endif