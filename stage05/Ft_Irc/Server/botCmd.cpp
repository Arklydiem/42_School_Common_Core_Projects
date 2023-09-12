/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   botCmd.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:18:49 by argomez           #+#    #+#             */
/*   Updated: 2023/05/29 17:39:11 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_irc.h"

void	Server::botCmd(std::map<int, Client*>::iterator it, std::vector<std::string> args)
{
	std::string message = it->second->getNickname() + " -> ";
	for (size_t i = 0; i < args.size(); i++)
	{
		message += args[i];
		if (i < args.size() - 1)
			message += " ";
	}
	message += "\n";
	if (isValidClient("bot") == true)
	{
		int botFd = getClientByName("bot")->getClientFd();
		sendToClient(botFd, message);
	}
	else
		sendToClient(it->first, BOT_DISABLED);
}
