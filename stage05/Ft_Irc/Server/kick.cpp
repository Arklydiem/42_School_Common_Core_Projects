/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kick.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:17:52 by vnadal            #+#    #+#             */
/*   Updated: 2023/05/11 17:51:41 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_irc.h"

int		Server::checkingKickError(std::map<int, Client*>::iterator it, std::string channel, std::string toKick)
{
	if (it->second->isInChannel(channel) == false)
	{
		sendToClient(it->first, KICK_NOT_IN_CHANNEL + channel + "\n");
		return (FAIL);
	}
	if (getChannelByName(channel)->isClientOp(it->first) == false)
	{
		sendToClient(it->first, KICK_NO_PRIVILEGES + channel + "\n");
		return (FAIL);
	}
	if (getChannelByName(channel)->isClientInChannel(toKick) == false)
	{
		sendToClient(it->first, KICK_NOT_USER_IN_CHANNEL + toKick + " on channel " + channel + "\n");
		return (FAIL);
	}
	return (SUCCESS);
}

void	Server::getKickComment(std::vector<std::string> args, Channel *channel, Client *toKick)
{
	std::string comment = aggregateArgs(args, 2);
	std::string message = INFO;
	if (comment.empty())
		sendToClient(toKick->getClientFd(), message + GOT_KICKED + channel->getName() + "\"\n");
	else
		sendToClient(toKick->getClientFd(), message + GOT_KICKED + channel->getColor() + "#" + channel->getName() + "\e[0m\"" + "\n[Reason]: " + comment + "\n");
	channel->printDisconnectionToChannel(toKick, " got kicked of the channel ");
}

void	Server::kickCmd(std::map<int, Client*>::iterator it, std::vector<std::string> args)
{
	std::vector<std::string> channels;
	if (args.size() > 0)
		split(args[0], ",", channels);
	std::vector<std::string> usersToKick;
	if (args.size() > 1)
		split(args[1], ",", usersToKick);

	if (channels.empty() || usersToKick.empty() || usersToKick.size() != channels.size())
	{
		sendToClient(it->first, KICK_USAGE);
		return ;
	}
	
	int size = usersToKick.size();
	for (int i = 0; i != size; i++)
	{
		if (checkingKickError(it, channels[i], usersToKick[i]) == FAIL)
			continue ;
		else
		{
			if (usersToKick[i] == it->second->getNickname())
			{
				sendToClient(it->first, KICK_SELF);
				continue ;
			}
			Client *toKick = getClientByName(usersToKick[i]);
			getChannelByName(channels[i])->removeClientFromChannel(toKick->getClientFd());
			toKick->removeCurrentChannel(channels[i]);
			getKickComment(args, getChannelByName(channels[i]), toKick);
		}
	}
}