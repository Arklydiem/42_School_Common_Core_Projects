/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invite.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:17:55 by vnadal            #+#    #+#             */
/*   Updated: 2023/05/11 18:26:19 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_irc.h"

void		Server::inviteCmd(std::map<int, Client*>::iterator it, std::vector<std::string> args)
{
	if (args.size() != 2)
	{
		sendToClient(it->first, INVITE_USAGE);
		return ;
	}
		
	std::vector<std::string> channels;
	split(args[0], ",", channels);
	
	std::vector<std::string> toInvite;
	split(args[1], ",", toInvite);

	if (channels.size() != toInvite.size() || channels.empty() == true)
	{
		sendToClient(it->first, INVITE_USAGE);
		return ;
	}
	int size = channels.size();
	for (int i = 0; i < size; i++)
	{
		if (chanExists(channels[i]) == false)
		{
			sendToClient(it->first, INVITE_NO_SUCH_CHAN + channels[i] + "\n");
			continue;
		}
		Channel *channel = getChannelByName(channels[i]);
		if (channel->getInviteMode() == false)
		{
			sendToClient(it->first, INVITE_NOT_SET + channels[i] + "\n");
			continue ;
		}
		if (channel->isClientInChannel(it->second->getNickname()) == false)
		{
			sendToClient(it->first, INVITE_NOT_IN_CHANNEL + channels[i] + "\n");
			continue ;
		}
		if (channel->isClientOp(it->first) == false)
		{
			sendToClient(it->first, INVITE_NO_PRIVILEGES + channels[i] + "\n");
			continue ;
		}
		if (isValidClient(toInvite[i]) == true)
		{
			if (channel->clientIsInInvite(toInvite[i]) == true)
				sendToClient(it->first, INVITE_THREE + toInvite[i] + " is already invited to the channel :" + channels[i] + "\n" );
			else
			{
				channel->addToInviteList(toInvite[i]);
				sendToClient(it->first, INVITE_TWO + toInvite[i]  + " is invited to the channel : " + channels[i] + "\n");
				std::string message = INFO;
				sendToClient(getClientByName(toInvite[i])->getClientFd(), message + "you're invited in the channel : " + channels[i] + "\n");
			}
		}
		else
			sendToClient(it->first, INVITE_NO_USER_EXIST + toInvite[i] + "\n");
	}
}
