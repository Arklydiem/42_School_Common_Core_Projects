/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:03:37 by argomez           #+#    #+#             */
/*   Updated: 2023/03/02 19:19:29 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		HARL_HPP
# define 	HARL_HPP

#include <iostream>
#include <string>

class Harl{
	private:
		void	debug(void);
		void	info(void);
		void	warning(void);
		void	error(void);
	public:
		Harl();
		~Harl();
		void	complain(std::string level);
		
};

#endif