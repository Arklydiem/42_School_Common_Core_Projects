/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bot.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:12:32 by argomez           #+#    #+#             */
/*   Updated: 2023/05/29 17:39:07 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <cstring>
#include <map>
#include <cstdlib>
#include <csignal>
#include <cstdio>
#include <cerrno>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#define PRIV "PRIVMSG "

class Bot
{
	public:
		void	run(void);
		void	processReception(std::string input);
		void	printDugtrio(std::string client);
		void	printCOUB(std::string client);
		void	printHelp(std::string client);
		void	printLogs(std::string input);
		void	printElse(std::string client);

		Bot(int port, std::string password);
		Bot(int port, std::string password, std::string logsMode);
		~Bot();
	private:
		int			_port;
		std::string	_password;
		int			_serverFd;
		bool		_logsMode;
};
