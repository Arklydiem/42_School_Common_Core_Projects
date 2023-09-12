/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 09:57:07 by vnadal            #+#    #+#             */
/*   Updated: 2023/05/11 11:47:19 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_irc.h"

void	Server::nickCmd(std::map<int, Client*>::iterator it, std::vector<std::string> args)
{
	std::string message;
	
	if (args.size() != 1)
	{
		sendToClient(it->first, NICK_USAGE);
		return ;
	}

	/* ************************** GETTING APPROPRIATE MESSAGE **************************** */
	if (it->second->getNickname().empty())
		message = NICK_SET;
	else
		message = NICK_CHANGE;

	/* *********************** CHECKING IF NICKNAME IS AVAILABLE ************************* */
	for (std::map<int, Client*>::iterator it2 = _clients.begin(); it2 != _clients.end(); it2++)
	{
		if (it2->second->getNickname() == args[0])
		{
			message = NICK_ISUSED;
			sendToClient(it->first, message);
			return ;
		}
	}
	it->second->setClientNickname(args[0]);
	it->second->setClientStatus(NICK);
	sendToClient(it->first, message);
}