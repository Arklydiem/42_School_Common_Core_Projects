/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   user.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 09:57:21 by vnadal            #+#    #+#             */
/*   Updated: 2023/05/30 16:37:55 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_irc.h"

void	Server::userCmd(std::map<int, Client*>::iterator it, std::vector<std::string> args)
{
	std::string realName;

	if (it->second->getClientStatus() == REGISTERED)
	{
		sendToClient(it->first, USER_ALREADY_REGISTER);
		return ;
	}

	if (args.size() < 4)
	{
		sendToClient(it->first, USER_USAGE);
		return ;
	}
	/* ******************** REAL NAME IS LAST ARG AND CAN CONTAIN SPACE ****************** */
	/* ************** ARGS ARE SPLITTED ON SPACE SO WE AGGREGATE REAL NAME  ************** */
	/* ************************* AND ADDING SPACE IF NOT LAST ARG ************************ */
	realName = aggregateArgs(args, 3);
	it->second->setClientUsername(args[0]);
	it->second->setClientHostName(args[1]);
	std::string serverName;
	for (size_t i = 3; i < args.size(); i++)
		serverName += args[i];
	it->second->setClientServerName(args[2]);
	it->second->setClientRealName(realName);
	it->second->setClientStatus(REGISTERED);
	sendToClient(it->first, USER_SUCCESSFULLY_REGISTER);
}