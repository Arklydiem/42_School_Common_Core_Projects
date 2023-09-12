/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 13:18:25 by vnadal            #+#    #+#             */
/*   Updated: 2023/05/30 16:56:24 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Server.hpp"

/* *************************************************************************************** */
/*                                       CONSTRUCTOR                                       */
/* *************************************************************************************** */

Server::Server(std::string port, std::string password)
{
	_port = atoi(port.c_str());
	_serverFd = 0;
	_password = password;
}

/* *************************************************************************************** */
/*                                       DESTRUCTOR                                        */
/* *************************************************************************************** */

Server::~Server()
{
	for (std::map<int, Client*>::iterator it = _clients.begin(); it != _clients.end(); it++)
	{
		close(it->first);
		delete it->second;
	}
	for (std::map<std::string, Channel*>::iterator it = _channels.begin(); it != _channels.end(); it++)
	{
		delete it->second;
	}
	close(_serverFd);
}

/* ************************************ EXPLANATION ************************************** */
/* Clear an fd_set
FD_ZERO(&readfds);  

// Add a descriptor to an fd_set
FD_SET(_serverFd, &readfds);   

// Remove a descriptor from an fd_set
FD_CLR(_serverFd, &readfds); 

//If something happened on the server socket , then its an incoming connection  
FD_ISSET(_serverFd, &readfds); */

/* ********************************* END OF EXPLANATION ********************************** */

/* *************************************************************************************** */
/*                                       METHODS                                           */
/* *************************************************************************************** */

/* --------------------------------------- UTILS ----------------------------------------- */

int	Server::processReception(std::map<int, Client*>::iterator it, Command cmd)
{
	std::string token = cmd.getToken();
	printDebug(token);
	std::vector<std::string> args = cmd.getArgs();

	printServer("Client " + getClientInColor(it->first) + " : " + token);
	
	/* ************************** CHECKING CMD SENT BY CLIENT **************************** */
	if (token.compare("") == 0)
		sendToClient(it->first, "[\e[38;5;3mINFO\e[0m] Command not found.\n");
	else if (token.compare("PASS") == 0)
	{
		if (passCmd(it, args) == FAIL)
			return (FAIL);
	}
	else if (it->second->getClientStatus() <= GUEST)
		sendToClient(it->first, "[\e[38;5;3mINFO\e[0m] You need to be Logged Fisrt.\n");
	else if (token.compare("NICK") == 0 && it->second->getClientStatus() > GUEST)
		nickCmd(it, args);
	else if (it->second->getClientStatus() <= LOGGED)
		sendToClient(it->first, "[\e[38;5;3mINFO\e[0m] You need to set a NickName Fisrt.\n");
	else if (token.compare("USER") == 0 && it->second->getClientStatus() > LOGGED)
		userCmd(it, args);
	else if (it->second->getClientStatus() == NICK)
		sendToClient(it->first, "[\e[38;5;3mINFO\e[0m] You need to Register First.\n");
	else if (token.compare("JOIN") == 0 && it->second->getClientStatus() == REGISTERED)
		joinCmd(it, args);
	else if (token.compare("MODE") == 0 && it->second->getClientStatus() == REGISTERED)
		modeCmd(it, args);
	else if (token.compare("TOPIC") == 0 && it->second->getClientStatus() == REGISTERED)
		topicCmd(it, args);
	else if (token.compare("KICK") == 0 && it->second->getClientStatus() == REGISTERED)
		kickCmd(it, args);
	else if (token.compare("INVITE") == 0 && it->second->getClientStatus() == REGISTERED)
		inviteCmd(it, args);
	else if (token.compare("PART") == 0 && it->second->getClientStatus() == REGISTERED)
		partCmd(it, args);
	else if (token.compare("PRIVMSG") == 0 && it->second->getClientStatus() == REGISTERED)
		privMsgCmd(it, args);
	else if (token.compare("!bot") == 0 && it->second->getClientStatus() == REGISTERED)
		botCmd(it, args);
	return (SUCCESS);
}

void	Server::handleReception(int clientFd, std::string buffer)
{
	/* ********************** MAKING SURE WE RECEIVED EVERYTHING ************************* */
	std::map<int, Client*>::iterator it;
	Client *currentClient;
	
	it = _clients.find(clientFd);
	currentClient = it->second;

	currentClient->aggregateMessage(buffer);
	
	/* ******************** IF WE RECEIVED EVERYTHING THEN PROCESS *********************** */
	/* We will need to check is we received multiple commands as some client send Pass and */
	/*   Nick and User at the same time. Those commands will be delimited by \n so we get  */ 
	/*		line on the full input to get each command and then lauch each command		   */
	
	if (currentClient->getMessage().find('\n') != std::string::npos)
	{
		std::string currentMessage = currentClient->getMessage();
		printDebug("Client " + getClientInColor(it->first) + " Entry: " + currentMessage.substr(0, currentMessage.length() - 1));
		
		std::string line;
		std::istringstream input(currentClient->getMessage());
		it->second->getMessage().clear();
		while (getline(input, line))
		{
			Command command(line);
			if (processReception(it, command) == FAIL)
				break ;
		}
	}
}

void	Server::disconnectClient(int clientFd)
{
	//Il faut egalement le supprimé des clients actif d'un channel
	//Faire une fonction DisconnectClientFromChannel par exemple
	printServer("Client " + getClientInColor(clientFd) + " Disconnected.");
	
	/* ********************** DELETE IT FROM SERVER'S CLIENT LIST ************************ */
	std::map<int, Client*>::iterator it = _clients.find(clientFd);
	std::map<std::string, Channel*> currentChannel = it->second->getClientCurrentChannels();

	for (std::map<std::string, Channel *>::iterator it2 = currentChannel.begin(); it2 != currentChannel.end(); it2++)
	{
		it2->second->printDisconnectionToChannel(it->second, " has left ");
		it2->second->removeClientFromChannel(clientFd);
		if (it2->second->getCurrentClients().empty())
		{
			_channels.erase(it2->second->getName());
			delete it2->second;
		}
	}
	delete it->second;
	_clients.erase(it);
	close(clientFd);
}

int		Server::checkingClientsActivity(fd_set& readfds, sockaddr_in& address)
{
	(void)address;
	int 	clientFd;
	ssize_t	receivedBytes;
	char	buffer[1024];

	for (std::map<int, Client*>::iterator it = _clients.begin(); it != _clients.end() ;)
	{
		clientFd = it->first;
		
		/* ********************* CHECK IF CURRENT CLIENT IS ACTIVE *********************** */
		if (FD_ISSET(clientFd, &readfds))
		{
			receivedBytes = recv(clientFd, &buffer, sizeof(buffer), 0);
			buffer[receivedBytes] = '\0';
			if (receivedBytes < 0)
				return (FAIL);
				
			/* ********************* CHECKING IF CLIENT DISCONNECT ********************** */
			else if (receivedBytes == 0)
			{
				it++;
				disconnectClient(clientFd);
				if (_clients.empty())
					return (SUCCESS);
			}
			
			/* *********************** ELSE CLIENT SENT SOMETHING ************************ */
			else
			{
				it++;
				if (receivedBytes > 1000)
				{
					buffer[0] = '\0';
					sendToClient(clientFd, ERR_MSG_TOO_LONG);
					continue;
				}
				handleReception(clientFd, buffer);
				if (_clients.empty())
					return (SUCCESS);
			}
			receivedBytes = 0;
		}
		else
			it++;
	}
	return (SUCCESS);
}

int		Server::handleNewConnexion(fd_set& readfds, sockaddr_in& address)
{
	int tmpFd;
	int addressLen = (sizeof(address));
	
	if (FD_ISSET(_serverFd, &readfds))  
	{  
		if ((tmpFd = accept(_serverFd, (struct sockaddr *)&address, (socklen_t*)&addressLen)) < 0)  
		{  
			Error::printError(ERR_ACCEPT);
			return (FAIL);
		}  
		else
		{
			_clients.insert(std::pair<int, Client*>(tmpFd, new Client(tmpFd, this)));
			printServer("Client " + getClientInColor(tmpFd) + " Connected.");
			printBanner(tmpFd);
			sendToClient(tmpFd, "[\e[38;5;3mINFO\e[0m] Connected on Server.\n");
		}
	}
	return (SUCCESS);
}

void	Server::resetAllFds(fd_set& readfds)
{
	int tmpFd;

	FD_ZERO(&readfds);  
	FD_SET(_serverFd, &readfds);  
	_maxFd = _serverFd;  

	for (std::map<int, Client*>::iterator it = _clients.begin(); it != _clients.end(); it++)
	{
		tmpFd = it->first;
		if(tmpFd > 0)  
			FD_SET(tmpFd , &readfds);  
				
		if(tmpFd > _maxFd)  
			_maxFd = tmpFd;  
	}
}

void	Server::printDebug(std::string toPrint)
{
	if (DEBUG_MODE == true)
		std::cout << getTime() << toPrint << std::endl;
}

void	Server::printServer(std::string toPrint)
{
	if (SERVER_MODE == true)
		std::cout << getTime() << toPrint << std::endl;
}

std::string Server::getClientInColor(int clientFd)
{
	return ("\e[38;5;" + itoa(clientFd % 230) + "m" + itoa(clientFd) + "\e[0m");
}

std::string	Server::itoa(int toConvert)
{
	std::stringstream toString;
	toString << toConvert;
	return (toString.str());
}

std::string	Server::getTime(void){
	time_t rawtime;
	struct tm * timeinfo;
	char buffer [12];

	time (&rawtime);
	timeinfo = localtime (&rawtime);

	strftime (buffer,18,"[%H:%M:%S] ",timeinfo);
	std::string hour = buffer;
	return (hour);
}



/* ------------------------------ MAIN FUNCTION OF SERVER -------------------------------- */

void Server::run(void)
{
	struct sockaddr_in	address;
	int					select_action;
	fd_set				readfds;
	int					opt = 1;

	/* ******************************** CREATING SOCKET ********************************** */
	if ((_serverFd = socket(AF_INET, SOCK_STREAM, 0)) == FAIL)
	{
		Error::printError(ERR_SOCKET);
		return ;
	}
	address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(_port);
	memset(address.sin_zero, 0, 8);


	/* ******************* SETTING OPTION TO SOCKET TO REUSE FASTER ********************** */
	if(setsockopt(_serverFd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt)) == FAIL)  
    {  
		Error::printError(ERR_BIND);
		return ;
    }  

	/* ********************* BINDING SOCKET TO LOCALHOST AND PORT ************************ */
	if (bind(_serverFd, (struct sockaddr *)&address, sizeof(struct sockaddr)) == FAIL)
	{
		Error::printError(ERR_BIND);
		return ;
	}

	/* *************************** LISTENING ON SERVER SOCKET **************************** */
	if (listen(_serverFd, 3) == FAIL)  
    {  
		Error::printError(ERR_LISTEN);
		return ;
    }  

	/* ************************************ MAIN LOOP ************************************ */
	while (1)
	{
		/* ************************** CLEARING AND SETTING FDS *************************** */
		resetAllFds(readfds);		

		printDebug("Select");
		/* *********************** WAITING FOR ACTIONS ON SERVER ************************* */
		select_action = select((_maxFd + 1), &readfds, NULL, NULL, NULL);
		if (select_action == FAIL)
		{
			if (errno != EINTR)
				Error::printError(ERR_SELECT);
			return ;
		}

		/* ********************** CHECK IF NEW CLIENT IS CONNECTED *********************** */
		if (handleNewConnexion(readfds, address) == FAIL)
			return ;
			
		/* ******************** CHECKING FOR CONNECTED CLIENT ACTIVITY ******************* */
		if (checkingClientsActivity(readfds, address) == FAIL)
			return ;
	}
}