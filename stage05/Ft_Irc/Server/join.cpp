/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 12:05:04 by vnadal            #+#    #+#             */
/*   Updated: 2023/05/30 15:24:23 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

template <typename T>
void	Server::split(std::string line, std::string limiter, T& dest)
{
	size_t pos = 0;
	std::string input;

	while ((pos = line.find(limiter)) != std::string::npos)
	{
		input = line.substr(0, pos);
		dest.push_back(input);
		line.erase(0, pos + limiter.size());
		printDebug("Input: " + input);
	}
	if (!line.empty())
	{
		input = line.substr(0, pos);
		dest.push_back(input);
		printDebug("Input: " + input);
	}
}

int	Server::getJoinArgs(std::vector<std::string> args, std::vector<std::string>& channels, std::vector<std::string>& keys)
{
	if (args.size() < 1 || args.size() > 2)
	{
		printDebug("Error number of arguments");
		return (FAIL);
	}
	/* ******************** GETTING EACH CHANNEL AND CORRESPONDING KEY ******************* */
	split(args[0], ",", channels);
	if (args.size() == 2)
		split(args[1], ",", keys);
	if (keys.size() > channels.size())
		return (FAIL);
	/* ******************* FILLING WITH EMPTY KEYS TO MAKE CHECK EASIER ****************** */
	if (keys.size() < channels.size())
	{
		std::vector<std::string>::iterator it = keys.end(); 
		keys.insert(it, (channels.size() - keys.size()), "");
	}
	return (SUCCESS);
}

int		Server::IsValidChannelSyntax(std::string channel)
{
	if (channel.size() > 200 || channel.empty())
		return (FAIL);
	return (SUCCESS);
}

int		Server::isValidAssociation(Channel *channel, std::string keyGiven, int clientFd)
{
	std::string channelKey = channel->getKey();
	/* ****************** IF CHANNEL DOESNT HAVE A KEY AND USER GAVE ONE ***************** */
	/* *********************** WE SAY THAT NO CHANNEL CORRESPONDS ************************ */
	if (channelKey.empty() && !keyGiven.empty())
	{
		sendToClient(clientFd, JOIN_NO_SUCH_CHANNEL + channel->getName() + '\n');
		return (FAIL);
	}
	/* ******************** IF CHANNEL HAVE A KEY AND USER GAVE NONE ********************* */
	/* *********************** WE SAY THAT NO CHANNEL CORRESPONDS ************************ */
	if (!channelKey.empty() && keyGiven.empty())
	{
		sendToClient(clientFd, JOIN_NO_SUCH_CHANNEL + channel->getName() + '\n');
		return (FAIL);
	}
	/* ******************************* IF KEY DOESNT MATCH ******************************* */
	if (channelKey.compare(keyGiven) != 0)
	{
		sendToClient(clientFd, JOIN_INVALID_KEY + channel->getName() + "\n");
		return (FAIL);
	}
	return (SUCCESS);
}

void	Server::joinCmd(std::map<int, Client*>::iterator it, std::vector<std::string> args)
{
	std::vector<std::string> channels;
	std::vector<std::string> keys;

	if (getJoinArgs(args, channels, keys) == -1)
	{
		sendToClient(it->first, JOIN_USAGE);
		return ;
	}
	std::vector<std::string>::iterator itKeys = keys.begin();
	for (std::vector<std::string>::iterator it2 = channels.begin(); it2 != channels.end(); it2++)
	{
		/* ********************** CHECKING IF CHANNEL NAME IS VALID ********************** */
		if (IsValidChannelSyntax(*it2) == FAIL)
		{
			sendToClient(it->first, JOIN_NO_SUCH_CHANNEL + *it2 + "\n");
			itKeys++;
			continue ;
		}
		/* *************** CHECKING IF CLIENT CAN CONNECT TO A NEW CHANNEL *************** */
		if (it->second->getClientCurrentChannels().size() >= MAX_CHANNEL)
		{
			sendToClient(it->first, JOIN_TOO_MANY);
			itKeys++;
			continue ;
		}
		/* ********************* IF CHANN DOEST EXIST WE CREATE IT *********************** */
		if (chanExists(*it2) == false && !(*it2).empty())
		{
			//voir comment on gere le empty channel name
			createChannel(*it2, it, *itKeys);
			printServer("Channel [" + *it2 + "] created with key [" + *itKeys + "]");
			itKeys++;
			continue ;
		}
		Channel *channel = getChannelByName(*it2);
		/* ************************ CHECKING IF WE GOT VALID KEY ************************* */
		if (itKeys != keys.end() && isValidAssociation(channel, *itKeys, it->first) == FAIL)
		{
			itKeys++;
			continue ;
		}
		/* ******************* CHECKING IF WE ALREADY ARE IN CHANNEL ********************* */
		else if (it->second->isInChannel(*it2) == true)
		{
			sendToClient(it->first, JOIN_ALREADY_IN_CHANN + *it2 + "\n");
			itKeys++;
			continue ;
		}
		/* ******************** MANQUE LE CHECK DU INVITE ONLY MODE ********************** */
		else if (channel->getInviteMode() == true && channel->clientIsInInvite(it->second->getNickname()) == false)
		{
			sendToClient(it->first, JOIN_NOT_INVITED + channel->getName() + "\n");
			itKeys++;
			continue ;
		}
		else if (channel->getUserLimit() > 0 && (size_t)channel->getUserLimit() <= channel->getCurrentClients().size())
		{
			sendToClient(it->first, JOIN_MAX_USER_REACH + channel->getName() + "\n");
			itKeys++;
			continue ;
		}
		else
		{
			if (channel->getInviteMode() == true)
				channel->removeClientFromInviteList(it->second->getNickname());
			joinChannel(it, channel);
		}
		itKeys++;
	}
}
