/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 11:43:38 by vnadal            #+#    #+#             */
/*   Updated: 2023/05/30 16:40:48 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Channel.hpp"

/* *************************************************************************************** */
/*                                       CONSTRUCTOR                                       */
/* *************************************************************************************** */

Channel::Channel(std::string name, std::string key)
{
	_name = name;
	_key = key;
	_topicChangeMode = true;
	_inviteMode = false;
	_userLimit = -1;
	_topic = "";
	_color = "\e[48;5;53m";
}

/* *************************************************************************************** */
/*                                       DESTRUCTOR                                        */
/* *************************************************************************************** */

Channel::~Channel()
{
}

/* *************************************************************************************** */
/*                                       SETTERS                                           */
/* *************************************************************************************** */

void	Channel::setKey(std::string key)
{
	_key = key;
}

void	Channel::setInviteMode(bool setTo)
{
	_inviteMode = setTo;
}

void	Channel::setTopChangeMode(bool setTo)
{
	_topicChangeMode = setTo;
}

void	Channel::setUserLimit(int value)
{
	_userLimit = value;
}

void	Channel::setColor(std::string value)
{
	_color = value;
}

/* *************************************************************************************** */
/*                                       GETTERS                                           */
/* *************************************************************************************** */

std::string	Channel::getKey(void)
{
	return (_key);	
}

std::string	Channel::getName(void)
{
	return (_name);
}

std::string	Channel::getTopic(void)
{
	return (_topic);
}

bool		Channel::getInviteMode(void)
{
	return (_inviteMode);
}

bool		Channel::getTopChangeMode(void)
{
	return (_topicChangeMode);
}

int			Channel::getUserLimit(void)
{
	return (_userLimit);
}

std::string	Channel::getColor(void)
{
	return (_color);
}


t_chanClient&		Channel::getClientByName(std::string name)
{
	for (std::map<int, t_chanClient>::iterator it = _currentClient.begin(); it != _currentClient.end(); ++it)
		if (it->second.client->getNickname() == name)
    		return (it->second);
	return (_currentClient.begin()->second);
}

std::map<int, t_chanClient>& Channel::getCurrentClients(void)
{
	return (_currentClient);
}



/* *************************************************************************************** */
/*                                       METHODS                                           */
/* *************************************************************************************** */

void		Channel::addToInviteList(std::string name)
{
	_invited.push_back(name);
}


void		Channel::removeClientFromInviteList(std::string clientName)
{
	for (std::vector<std::string>::iterator it = _invited.begin(); it != _invited.end(); it++)
	{
		if (clientName == *it)
		{
			_invited.erase(it);
			return ;
		}
	}
}


bool		Channel::clientIsInInvite(std::string clientName)
{
	for (std::vector<std::string>::iterator it = _invited.begin(); it != _invited.end(); it++)
	{
		if (clientName == *it)
			return (true);
	}
	return (false);
}


bool	Channel::isClientOp(int clientFd)
{
	for (std::map<int, t_chanClient>::iterator it = _currentClient.begin(); it != _currentClient.end(); it++)
	{
		if (clientFd == it->first)
			return (it->second.isOp);
	}
	return (false);
}

bool	Channel::isClientInChannel(std::string name)
{
	for (std::map<int, t_chanClient>::iterator it = _currentClient.begin(); it != _currentClient.end(); it++)
	{
		if (it->second.client->getNickname() == name)
			return (true);
	}
	return (false);
}

void	Channel::addClientToChannel(Client *client, bool op)
{
	int clientFd = client->getClientFd();
	t_chanClient newClient =  {client, op};
	_currentClient.insert(std::pair<int, t_chanClient>(clientFd, newClient));
	printNewConnexionToChannel(client);
	printTopic(client->getClientFd());
	printUserList(client->getClientFd());
}

void	Channel::sendToClient(int clientFd, std::string message)
{
		int byteSend = send(clientFd, message.c_str(), message.size(), 0);
		if (byteSend < 0)
			std::cout << "[ERROR] Failed to send message to client" << std::endl;
		else if (byteSend < (int)message.size())
			std::cout << "[WARNING] Send message incomplete" << std::endl;
}

void		Channel::printTopic(int newClientFd)
{
	std::string message = "   topic: " + _topic + "\n";
	
	sendToClient(newClientFd, message);
}

void		Channel::printUserList(int newClientFd)
{
	std::string message;

	message = "   users: \n";
	sendToClient(newClientFd, message);
	for (std::map<int, t_chanClient>::iterator it = _currentClient.begin() ; it != _currentClient.end(); it++)
	{
		message = "      " + it->second.client->getNickname() + "\n";
		sendToClient(newClientFd, message);
	}
}

void		Channel::printNewConnexionToChannel(Client *client)
{
	int clientFd;

	for (std::map<int, t_chanClient>::iterator it = _currentClient.begin() ; it != _currentClient.end(); it++)
	{
		clientFd = it->second.client->getClientFd();
		sendToClient(clientFd, _color + "#" + _name + "\e[0m -> " + client->getNickname() + " joined the channel\n");
	}
}

void		Channel::printDisconnectionToChannel(Client *client, std::string message)
{
	int clientFd;
	std::string finalMessage = client->getNickname() + message + _name + "\n";

	for (std::map<int, t_chanClient>::iterator it = _currentClient.begin() ; it != _currentClient.end(); it++)
	{
		clientFd = it->second.client->getClientFd();
		if (clientFd != client->getClientFd())
			sendToClient(clientFd, _color + "#" + _name + "\e[0m -> " + client->getNickname() + " left the channel\n");
	}
}

void	Channel::removeClientFromChannel(int clientToRemove)
{
	std::map<int, t_chanClient>::iterator it = _currentClient.find(clientToRemove);
	_currentClient.erase(it);
}


void	Channel::setTopic(std::string newTopic)
{
	_topic = newTopic;
}

void	Channel::setClientOpModeTo(std::string client, bool value)
{
	if (isClientInChannel(client) == false)
		return;
	getClientByName(client).isOp = value;
}