/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 09:57:20 by vnadal            #+#    #+#             */
/*   Updated: 2023/05/12 12:18:25 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "../ft_irc.h"

class Client;
class Channel;
class Command;

class Server
{
	public:
		/* ************************************************************************** */
		/*                                CONSTRUCTOR                                 */
		/* ************************************************************************** */

		Server(std::string port, std::string password);
	
		/* ************************************************************************** */
		/*                                DESTRUCTOR                                  */
		/* ************************************************************************** */

		~Server();

		/* ************************************************************************** */
		/*                                 METHODS                                    */
		/* ************************************************************************** */
		
		/* ---------------------------- MAIN FUNCTION ------------------------------- */

		void		run(void);
		void		resetAllFds(fd_set& readfds);
		void		disconnectClient(int clientFd);
		void		handleReception(int clientFd, std::string buffer);
		int			processReception(std::map<int, Client*>::iterator currentClient, Command cmd);
		int			handleNewConnexion(fd_set& readfds, sockaddr_in& address);
		int			checkingClientsActivity(fd_set& readfds, sockaddr_in& address);
		std::string	getCmd(std::string message);
		

		/* -------------------------------- UTILS ----------------------------------- */
		
		void		joinChannel(std::map<int, Client*>::iterator it, Channel *newChannel);
		void		sendToClient(int clientFd, std::string message);
		void		printBanner(int clientFd);
		void		createChannel(std::string name, std::map<int, Client*>::iterator it, std::string key);
		template <typename T>
		void		split(std::string line, std::string limiter, T& dest);
		bool		chanExists(std::string name);
		bool		isValidClient(std::string name);
		Channel		*getChannelByName(std::string name);
		Client*		getClientByName(std::string name);
		std::string	aggregateArgs(std::vector<std::string> args, size_t start);
		void		printDebug(std::string toPrint);
		void		printServer(std::string toPrint);
		std::string	getClientInColor(int clientFd);
		std::string	itoa(int toConvert);
		std::string	getTime(void);

		/* ------------------------------ COMMANDS ---------------------------------- */

	
		void		nickCmd(std::map<int, Client*>::iterator it, std::vector<std::string> args);
		void		userCmd(std::map<int, Client*>::iterator it, std::vector<std::string> args);
		void		joinCmd(std::map<int, Client*>::iterator it, std::vector<std::string> args);
		void		modeCmd(std::map<int, Client*>::iterator it, std::vector<std::string> args);
		void		topicCmd(std::map<int, Client*>::iterator it, std::vector<std::string> args);
		void		kickCmd(std::map<int, Client*>::iterator it, std::vector<std::string> args);
		void		inviteCmd(std::map<int, Client*>::iterator it, std::vector<std::string> args);
		void		partCmd(std::map<int, Client*>::iterator it, std::vector<std::string> args);
		void		privMsgCmd(std::map<int, Client*>::iterator it, std::vector<std::string> args);
		void		botCmd(std::map<int, Client*>::iterator it, std::vector<std::string> args);


		//a changer
		int			getJoinArgs(std::vector<std::string> args, std::vector<std::string>& channels, std::vector<std::string>& keys);
		int			isValidAssociation(Channel *channel, std::string keyGiven, int clientFd);
		int			passCmd(std::map<int, Client*>::iterator it, std::vector<std::string> args);
		int			IsValidChannelSyntax(std::string channel);

		//TOPIC
		void		makeChangeToTopic(Channel *channel, std::vector<std::string> args, int nbArgs);
		int			checkingTopicError(std::map<int, Client*>::iterator it, std::vector<std::string> args);

		//KICK
		int			checkingKickError(std::map<int, Client*>::iterator it, std::string channel, std::string toKick);
		void		getKickComment(std::vector<std::string> args, Channel *channel, Client *toKick);
		
		//modeCMD
		void		channelInviteMod(Channel* channel, int mode, std::string& message);
		void		channelKey(Channel* channel, int mode, std::string& message, std::vector<std::string> args, size_t index);
		void		channelOperator(Channel* channel, int mode, std::string& message, std::vector<std::string> args, size_t index);
		void		channelTopic(Channel* channel, int mode, std::string& message);
		void		channelLimit(Channel* channel, int mode, std::string& message, std::vector<std::string> args, size_t index);
		void		channelColor(Channel* channel, int mode, std::string& message);


	private:

		Server();
		Server(const Server& copy);
		Server& operator=(const Server& copy);
		
		/* ************************************************************************** */
		/*                                ATTRIBUTES                                  */
		/* ************************************************************************** */
		
		std::string 					_password;
		std::map<int, Client*> 			_clients;
		std::map<std::string, Channel*> _channels;
		int								_port;
		int								_serverFd;
		int								_maxFd;
};
