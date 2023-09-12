/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 09:26:08 by vnadal            #+#    #+#             */
/*   Updated: 2023/05/12 11:14:37 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../ft_irc.h"

class Command
{
	public:
		Command(std::string input);
		~Command();

		std::string getToken()
		{
			return (_token);
		}
		
		std::vector<std::string>& getArgs()
		{
			return (_args);
		}
		
	private:
	
		std::string _token;
		std::vector<std::string> _args;
};