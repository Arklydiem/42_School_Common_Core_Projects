/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 11:34:11 by argomez           #+#    #+#             */
/*   Updated: 2023/03/15 12:38:07 by argomez          ###   ########.fr       */
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
		std::string getIdea(int index);
		void		setIdea(std::string idea);
	protected:
		std::string	_ideas[100];
};

#endif