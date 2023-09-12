/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:18:12 by vnadal            #+#    #+#             */
/*   Updated: 2023/05/30 15:57:02 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Client.hpp"

/* *************************************************************************************** */
/*                                       CONSTRUCTOR                                       */
/* *************************************************************************************** */

Client::Client(int fd, Server *server)
{
	_clientFd = fd;
	_clientStatus = GUEST;
	(void)server;
	_server = server;
	_passwordTries = 0;
}

/* *************************************************************************************** */
/*                                       DESTRUCTOR                                        */
/* *************************************************************************************** */
Client::~Client()
{
}

/* *************************************************************************************** */
/*                                       SETTERS                                           */
/* *************************************************************************************** */

void	Client::setClientNickname(std::string nickname)
{
	_nickname = nickname;
}

void	Client::setClientUsername(std::string username)
{
	_userName = username;
}

void	Client::setClientStatus(int status)
{
	_clientStatus = status;
}

void	Client::setClientRealName(std::string input)
{
	std::size_t pos = input.find(":", 0);
	if (pos != std::string::npos)
	{
		std::string::iterator it = input.begin();
		std::advance(it, pos);
		input.erase(it);
	}
	_realName = input;
}

void	Client::setClientHostName(std::string input)
{
	_hostName = input;
}

void	Client::setClientServerName(std::string input)
{
	_serverName = input;
}

/* *************************************************************************************** */
/*                                       GETTERS                                           */
/* *************************************************************************************** */

std::string&	Client::getMessage(void)
{
	return (_message);	
}

std::string&	Client::getNickname(void)
{
	return (_nickname);
}

std::string&	Client::getRealName(void)
{
	return (_realName);
}

std::string&	Client::getHostName(void)
{
	return (_hostName);
}

std::string&	Client::getServerName(void)
{
	return (_serverName);
}

int&			Client::getClientStatus(void)
{
	return (_clientStatus);
}

std::string&	Client::getUsername(void)
{
	return (_userName);
}

int&	Client::getClientFd(void)
{
	return (_clientFd);
}

std::map<std::string, Channel *>& Client::getClientCurrentChannels(void)
{
	return (_channelJoined);
}

int&	Client::getPasswordTries(void)
{
	return (_passwordTries);
}

/* *************************************************************************************** */
/*                                       METHODS                                           */
/* *************************************************************************************** */

void	Client::aggregateMessage(std::string buffer)
{
	if (_message.empty())
		_message = buffer;
	else
		_message += buffer;
	std::size_t pos = _message.find("\r");
	if (pos != std::string::npos)
	{
		std::string::iterator it = _message.begin();
		std::advance(it, pos);
		_message.erase(it);
	}
	while ((pos = _message.find(4)) != std::string::npos)
	{
		std::string::iterator it = _message.begin();
		std::advance(it, pos);
		_message.erase(it);
	}
}

void	Client::addToCurrentChannel(Channel *newChannel, std::string name)
{
	_channelJoined.insert(std::pair<std::string, Channel *>(name, newChannel));
}

bool	Client::isInChannel(std::string channel)
{
	if (_channelJoined.find(channel) == _channelJoined.end())
		return (false);
	return (true);
}

void	Client::removeCurrentChannel(std::string channelName)
{
	std::map<std::string, Channel *>::iterator it = _channelJoined.find(channelName);
	_channelJoined.erase(it);
}
