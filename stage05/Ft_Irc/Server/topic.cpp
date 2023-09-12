/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   topic.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:17:50 by vnadal            #+#    #+#             */
/*   Updated: 2023/05/11 16:34:10 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_irc.h"


void	Server::makeChangeToTopic(Channel *channel, std::vector<std::string> args, int nbArgs)
{
	(void)nbArgs;
	std::string newTopic = aggregateArgs(args, 1);
	channel->setTopic(newTopic);
}

int		Server::checkingTopicError(std::map<int, Client*>::iterator it, std::vector<std::string> args)
{
	int nbArgs = args.size();
	if (nbArgs == 0)
	{
		sendToClient(it->first, TOPIC_USAGE);
		return (FAIL);
	}
	if (it->second->isInChannel(args[0]) == false)
	{
		sendToClient(it->first, TOPIC_NOT_IN_CHANNEL);
		return (FAIL);
	}
	Channel *channelToCheck = getChannelByName(args[0]);
	if (channelToCheck->getTopChangeMode() == true && channelToCheck->isClientOp(it->first) == false)
	{
		sendToClient(it->first, TOPIC_NO_PRIVILEGES);
		return (FAIL);
	}
	return (SUCCESS);
}

void	Server::topicCmd(std::map<int, Client*>::iterator it, std::vector<std::string> args)
{
	int nbArgs = args.size();
	if (checkingTopicError(it, args) == FAIL)
		return ;
	Channel *channelToCheck = getChannelByName(args[0]);
	printDebug(itoa(nbArgs));
	if (nbArgs == 1)
	{
		if (channelToCheck->getTopic().empty())
		{
			sendToClient(it->first, TOPIC_NOT_SET);
			return ;
		}
		sendToClient(it->first, TOPIC_IS + channelToCheck->getTopic() + "\n");
	}
	else
	{
		makeChangeToTopic(channelToCheck, args, nbArgs);
		sendToClient(it->first, TOPIC_SET + channelToCheck->getTopic() + "\n");
	}
}