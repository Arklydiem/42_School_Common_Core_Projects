/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 15:09:43 by vnadal            #+#    #+#             */
/*   Updated: 2023/05/29 17:50:08 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

void	Server::printBanner(int clientFd)
{
	std::string		line;
	std::ifstream in("banner", std::ofstream::in);
	if (!in)
		return ;
	while (getline(in, line))
	{
		line += "\n";
		if (clientFd == -1)
			std::cout << line;
		else
			sendToClient(clientFd, line);
	}
	in.close();
}

Channel*	Server::getChannelByName(std::string name)
{
	std::map<std::string, Channel*>::iterator channelIt = _channels.find(name);
	return (channelIt->second);
}

bool	Server::chanExists(std::string name)
{
	if (_channels.find(name) == _channels.end())
		return (false);
	return (true);
}

void	Server::sendToClient(int clientFd, std::string message)
{
	int byteSend = send(clientFd, message.c_str(), message.size(), 0);
	if (byteSend < 0)
		std::cout << "[ERROR] Failed to send message to client" << std::endl;
	else if (byteSend < (int)message.size())
		std::cout << "[WARNING] Send message incomplete" << std::endl;
}

void	Server::createChannel(std::string name, std::map<int, Client*>::iterator it, std::string key)
{
	Channel	*newChannel = new Channel(name, key);
	std::pair<std::string, Channel*> newPair(name, newChannel);
	_channels.insert(newPair);
	sendToClient(it->first, JOIN_CHANN_CREAT + name + "\n");
	newChannel->addClientToChannel(it->second, true);
	it->second->addToCurrentChannel(newChannel, name);

}

void	Server::joinChannel(std::map<int, Client*>::iterator it, Channel *newChannel)
{

	newChannel->addClientToChannel(it->second, false);
	it->second->addToCurrentChannel(newChannel, newChannel->getName());
	printServer(it->second->getNickname() + " joined " + newChannel->getName() + " channel");
}

Client*		Server::getClientByName(std::string name)
{
	for (std::map<int, Client *>::iterator it = _clients.begin(); it != _clients.end(); it++)
	{
		if (it->second->getNickname() == name)
			return (it->second);
	}
	return (NULL);
}

std::string		Server::aggregateArgs(std::vector<std::string> args, size_t start)
{
	std::string finalString = "";
	if (args.size() > start)
	{
		finalString = args[start];
		printDebug(finalString);
	}
	if (args.size() > start + 1)
	{
		finalString += " ";
		for (std::size_t i = start + 1; i < args.size(); i++)
		{
			finalString += args[i];
			if (i < args.size() - 1)
				finalString += " ";
		}
	}
	printDebug("[" + finalString + "]");
	return (finalString);
}

bool	Server::isValidClient(std::string name)
{
	for (std::map<int, Client *>::iterator it = _clients.begin(); it != _clients.end(); it++)
	{
		if (it->second->getNickname() == name)
			return (true);
	}
	return (false);
}
