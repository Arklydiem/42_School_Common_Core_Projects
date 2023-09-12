/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Client.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:18:15 by vnadal            #+#    #+#             */
/*   Updated: 2023/05/11 11:35:06 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../ft_irc.h"

class Channel;
class Server;

class Client
{
	public:
		/* ************************************************************************** */
		/*                                CONSTRUCTOR                                 */
		/* ************************************************************************** */
		
		Client(int fd, Server *server);
		
		/* ************************************************************************** */
		/*                                DESTRUCTOR                                  */
		/* ************************************************************************** */
		~Client();

		/* ************************************************************************** */
		/*                                 METHODS                                    */
		/* ************************************************************************** */

		void								aggregateMessage(std::string buffer);
		void								addToCurrentChannel(Channel *newchannel, std::string name);
		bool								isInChannel(std::string channel);
		void								removeCurrentChannel(std::string channelName);

		
		/* ************************************************************************** */
		/*                                 SETTERS                                    */
		/* ************************************************************************** */
		
		void								setClientNickname(std::string nickname);
		void								setClientUsername(std::string input);
		void								setClientRealName(std::string input);
		void								setClientServerName(std::string input);
		void								setClientHostName(std::string input);
		void								setClientStatus(int status);

		/* ************************************************************************** */
		/*                                 GETTERS                                    */
		/* ************************************************************************** */
		
		std::string&						getMessage(void);
		std::string&						getNickname(void);
		std::string&						getRealName(void);
		std::string&						getHostName(void);
		std::string&						getServerName(void);
		std::string&						getUsername(void);
		int&								getClientFd(void);
		int&								getClientStatus(void);
		std::map<std::string, Channel *>&	getClientCurrentChannels(void);
		int&								getPasswordTries(void);

	private:
		Client(const Client& copy);
		Client& operator=(const Client& copy);

		/* ************************************************************************** */
		/*                                ATTRIBUTES                                  */
		/* ************************************************************************** */
		
		int			_clientStatus;
		int			_clientFd;
		Server		*_server;
		int			_passwordTries;
		
		std::string	_nickname;
		std::string	_userName;
		std::string	_realName;
		std::string	_hostName;
		std::string	_serverName;
		std::string	_message;

		std::map<std::string, Channel *> _channelJoined;
};
