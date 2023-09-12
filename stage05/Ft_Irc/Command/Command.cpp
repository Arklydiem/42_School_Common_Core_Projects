/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Command.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/30 09:27:40 by vnadal            #+#    #+#             */
/*   Updated: 2023/05/12 13:47:07 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Command.hpp"

bool	isCmd(std::string input)
{
	if (input == "PASS" || input == "NICK" || input == "USER")
		return (true);
	else if (input == "JOIN" || input == "MODE" || input == "TOPIC")
		return (true);
	else if (input == "KICK" || input == "INVITE" || input == "PART")
		return (true);
	else if (input == "PRIVMSG" || input == "!bot")
		return (true);
	return (false);
}

Command::Command(std::string input)
{
	std::istringstream line(input);
	std::string	word;
	bool flag = false;
	
	/* ****************************** SPLITTING ON SPACE ********************************* */
	while (line >> word)
	{
		if (isCmd(word) == true && flag == false)
		{
			_token = word;
			flag = true;
		}
		else if (flag == true)
			_args.push_back(word);
	}
}

Command::~Command()
{
}