/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Channel.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 10:39:24 by vnadal            #+#    #+#             */
/*   Updated: 2023/05/11 14:55:59 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "../ft_irc.h"

class Client;

typedef struct s_chanClient
{
	Client *client;
	bool	isOp;
} t_chanClient;

class Channel
{
	public:
	
		/* ************************************************************************** */
		/*                                CONSTRUCTOR                                 */
		/* ************************************************************************** */
		
		Channel(std::string name, std::string key);

		/* ************************************************************************** */
		/*                                DESTRUCTOR                                  */
		/* ************************************************************************** */
		
		~Channel();
		
		/* ************************************************************************** */
		/*                                 GETTERS                                    */
		/* ************************************************************************** */
		
		std::string		getKey(void);
		std::string		getName(void);
		std::string		getTopic(void);
		bool			getInviteMode(void);
		bool			getTopChangeMode(void);
		int				getUserLimit(void);
		bool			clientIsInInvite(std::string clientName);
		t_chanClient&	getClientByName(std::string name);
		std::map<int, t_chanClient>& getCurrentClients(void);
		std::string		getColor(void);
		
		/* ************************************************************************** */
		/*                                 METHODS                                    */
		/* ************************************************************************** */
		
		void		addClientToChannel(Client *client, bool op);
		void		removeClientFromChannel(int clientToRemove);
		void		printTopic(int newClientFd);
		void		printUserList(int newClientFd);
		void		printNewConnexionToChannel(Client *client);
		void		printDisconnectionToChannel(Client *client, std::string message);

		void		sendToClient(int clientFd, std::string message);
		bool		isClientOp(int clientFd);
		bool		isClientInChannel(std::string name);
		void		removeClientFromInviteList(std::string clientName);
		void		addToInviteList(std::string name);
		
		/* ************************************************************************** */
		/*                                 SETTERS                                    */
		/* ************************************************************************** */
		void		setTopic(std::string newTopic);
		void		setKey(std::string key);
		void		setInviteMode(bool setTo);
		void		setTopChangeMode(bool setTo);
		void		setClientOpModeTo(std::string client, bool value);
		void		setUserLimit(int value);
		void		setColor(std::string color);


	private:

		/* ************************************************************************** */
		/*                                ATTRIBUTES                                  */
		/* ************************************************************************** */
		
		std::map<int, t_chanClient> _currentClient;
		std::string 				_name;
		std::string 				_key;
		std::vector<std::string>	_invited;
		std::string					_topic;
		std::string					_color;
		bool						_topicChangeMode;
		bool						_inviteMode;
		int							_userLimit;	
};	