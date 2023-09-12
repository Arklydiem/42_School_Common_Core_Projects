/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:34:11 by argomez           #+#    #+#             */
/*   Updated: 2023/03/22 17:30:35 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		BRAIN_HPP
# define	BRAIN_HPP

#include	<iostream>
#include	<string>

class Brain
{
	public:
		Brain ();
		Brain (const Brain&);
		Brain &operator=(const Brain&);
		~Brain ();
		const std::string getIdea(int index) const;
		void		setIdea(std::string idea);
	protected:
		std::string	_ideas[100];
};

#endif