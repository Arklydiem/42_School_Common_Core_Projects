#include <arpa/inet.h>
#include "Bot.hpp"
  
int serverFd = 0;

/*************************** CONSTRUCTORS ********************************/

Bot::Bot(int port, std::string password)
{
	_port = port;
	_password = password;
}

Bot::Bot(int port, std::string password, std::string logsMode)
{
	_port = port;
	_password = password;
	if (logsMode == "true")
		_logsMode = true;
	else
		_logsMode = false;
}

Bot::~Bot()
{
}

void	Bot::printDugtrio(std::string client)
{
	std::string message;
	std::string		line;
	std::string path = "Bot/dugtrio.txt";
	std::ifstream in(path.c_str(), std::ofstream::in);
	if (!in)
	{
		std::cout << "[BOT WARNING] : Impossible to open " << path << std::endl;
		return ;
	}
	while (getline(in, line))
	{
		message = PRIV + client + " ";
		line += "\n";
		message += line;
		send(_serverFd, message.c_str(), message.size(), 0);
		usleep(15);
		// printLogs(message);
	}
	in.close();
}

void	Bot::printCOUB(std::string client)
{
	std::string message;


	message = PRIV + client + " COUBEH\n";
	send(_serverFd, message.c_str(), message.size(), 0);
}

void	Bot::printElse(std::string client)
{
	std::string message;


	message = PRIV + client + " Sorry but this command does not exists\n";
	send(_serverFd, message.c_str(), message.size(), 0);
}

void	Bot::printHelp(std::string client)
{
	std::string startMessage;
	startMessage = PRIV + client + " ";

	std::string		message;
	std::string		line;
	std::ifstream	in("Bot/help", std::ofstream::in);
	size_t 			pos;
	if (!in)
	{
		std::cout << "[BOT WARNING] : Impossible to open " << "./help" << std::endl;
		return ;
	}
	while (getline(in, line))
	{
		message = startMessage;
		pos = line.find("HELP");
			if (pos != std::string::npos)
				message += "\e[38;5;3m";
		message += line;
		message += "\e[0m";
		message += "\n";
		send(_serverFd, message.c_str(), message.size(), 0);
		usleep(50);
		message = "";
	}
	in.close();
}

void	Bot::printLogs(std::string input)
{
	if (_logsMode == true)
		std::cout << input;
}

void	Bot::processReception(std::string input)
{
	printLogs(input);
	size_t pos = input.find("->");
	if (pos == std::string::npos)
		return ;
	std::string client = input.substr(0, pos - 1);
	std::string cmd = input.substr(pos + 3);
	pos = cmd.find("\n");
	std::string::iterator it = cmd.begin();
	if (pos != std::string::npos)
	{
		std::advance(it, pos);
		cmd.erase(it);
	}

	if (cmd.compare("topic<3") == 0)
		printDugtrio(client);
	else if (cmd.compare("coua") == 0)
		printCOUB(client);
	else if (cmd.compare("help") == 0)
		printHelp(client);
	else
		printElse(client);
}

void	handleSignal(int sig)
{
	(void)sig;
	close(serverFd);
	exit(1);
}

void	Bot::run(void)
{
	int status, valread, client_fd;
    struct sockaddr_in serv_addr;
    char buffer[1024] = { 0 };
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
	{
        return;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(_port);
  
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr) <= 0)
	{
        return;
    }
  
    if ((status = connect(client_fd, (struct sockaddr*)&serv_addr, sizeof(serv_addr))) < 0)
	{
        return;
    }
	_serverFd = client_fd;
	serverFd = client_fd;

	// std::signal(SIGINT, &handleSignal);

	char logs[] = "PASS test\nNICK bot\nUSER bot bot bot bot\n";
    send(client_fd, logs, 40, 0);

	while (1)
	{
    	valread = recv(client_fd, buffer, 1024, 0);
		if (valread <= 0)
		{
			close(client_fd);
			return ;
		}
		if (valread > 0)
			processReception(buffer);
		bzero(buffer, 1024);
		valread = 0;
	}

    close(client_fd);
    return ;
}
