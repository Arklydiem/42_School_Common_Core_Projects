/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:17:52 by vnadal            #+#    #+#             */
/*   Updated: 2023/05/11 18:29:33 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_irc.h"

void	Server::partCmd(std::map<int, Client*>::iterator it, std::vector<std::string> args)
{
	std::vector<std::string> channels;
	if (args.size() > 0)
		split(args[0], ",", channels);

	if (channels.empty() || args.size() < 1)
	{
		sendToClient(it->first, PART_USAGE);
		return ;
	}

	std::string message;

	size_t	size = channels.size();
	for (size_t i = 0; i < size; i++)
	{
		if (it->second->isInChannel(channels[i]) == false)
		{
			message	+= PART_NOT_IN_CHANNEL;
			message += channels[i] + "\n";
		}
		else
		{
			it->second->removeCurrentChannel(channels[i]);
			Channel* channel = getChannelByName(channels[i]);
			channel->removeClientFromChannel(it->second->getClientFd());
			message += PART_LEFT_CHANNEL;
			message	+= channels[i] + "\n";
			channel->printDisconnectionToChannel(it->second, " has left ");
			if (channel->getCurrentClients().empty())
			{
				_channels.erase(channel->getName());
				delete channel;
			}
		}
	}
	sendToClient(it->first, message);
}