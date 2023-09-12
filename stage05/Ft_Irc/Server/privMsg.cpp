/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   privMsg.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 11:17:52 by vnadal            #+#    #+#             */
/*   Updated: 2023/05/11 19:02:17 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_irc.h"

void	Server::privMsgCmd(std::map<int, Client*>::iterator it, std::vector<std::string> args)
{
	/* ****************************** SPLITTING ON DOT ********************************* */

	std::vector<std::string> receivers;
	if (args.size() > 0)
		split(args[0], ",", receivers);

	if (receivers.empty() || args.size() < 2)
	{
		sendToClient(it->first, PRIVMSG_USAGE);
		return ;
	}

	/* ****************************** CREATE THE MESSAGE TO SEND ********************************* */

	std::string message = it->second->getNickname();

	message += " ->";
	size_t size = args.size();
	for (size_t i = 1; i < size; i++)
		message += " " + args[i];

	message += "\n";

	
	/* ****************************** SEND MSG TO CLIENT OR/AND CHANNEL ********************************* */

	size = receivers.size();
	for (size_t i = 0; i < size; i++)
	{
		if (isValidClient(receivers[i]) == false && chanExists(receivers[i]) == false)
		{
			sendToClient(it->first, PRIVMSG_NO_USER_CHAN + receivers[i] + "\n");
			continue;
		}
		if (isValidClient(receivers[i]) == true)
			sendToClient(getClientByName(receivers[i])->getClientFd(), message);
		if (chanExists(receivers[i]) == true)
		{
			Channel* channel = getChannelByName(receivers[i]);
			std::string toChannel = channel->getColor() + "#" + channel->getName() + "\e[0m";
			if (channel->isClientInChannel(it->second->getNickname()) == false)
				continue;
			std::map<int, t_chanClient> channelUsers = channel->getCurrentClients();
			for (std::map<int, t_chanClient>::iterator itUser = channelUsers.begin(); itUser != channelUsers.end(); itUser++)
			{
				if (itUser->first == it->first)
					continue;
				sendToClient(itUser->first, toChannel + " " + message);
			}
		}
	}
}