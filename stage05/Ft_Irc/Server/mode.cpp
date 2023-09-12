/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 09:57:07 by vnadal            #+#    #+#             */
/*   Updated: 2023/05/12 10:58:18 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_irc.h"

void	Server::modeCmd(std::map<int, Client*>::iterator it, std::vector<std::string> args)
{
	
	if (args.size() < 2)
	{
		sendToClient(it->first, MODE_USAGE);
		return ;
	}

	/* ************************** MANAGE CHANNEL ERROR **************************** */

	if (!chanExists(args[0]))
	{
		sendToClient(it->first, MODE_NO_SUCH_CHANNEL + args[0] + "\n");
		return ;
	}

	if (it->second->isInChannel(args[0]) == false)
	{
		sendToClient(it->first, MODE_NOT_IN_CHANNEL + args[0] + "\n");
		return ;
	}

	Channel* channel =  getChannelByName(args[0]);

	/* ************************** MANAGE PERMISSION ERROR **************************** */

	if (channel->isClientOp(it->first) == false)
	{
		sendToClient(it->first, MODE_NO_PRIVILEGES + args[0] + "\n");
		return ;
	}

	/* ************************** MANAGE ARGS ERROR **************************** */

	if (args[1][0] != '+' && args[1][0] != '-')
	{
		sendToClient(it->first, MODE_USAGE);
		return ;
	}

	size_t	args_needed = 2;
	int		mode = false;

	for (size_t i = 0; args[1][i]; i++)
	{
		if (args[1][i] == '+' || args[1][i] == '-')
			mode = args[1][i++];
		if ((args[1][i] == 'k' && mode == '+') || args[1][i] == 'o' || (args[1][i] == 'l' && mode == '+'))
			args_needed++;
		else if (args[1][i] != 'k' && args[1][i] != 't' && args[1][i] != 'i' && args[1][i] != 'o' && args[1][i] != 'l' && args[1][i] != 'c')
		{
			sendToClient(it->first, MODE_USAGE);
			return ;
		}
	}

	size_t	size_args = args.size();
	
	if (args_needed != size_args)
	{
		sendToClient(it->first, MODE_NOT_ENOUGH_ARGS);
		return ;
	}

	/* ************************** MANAGE MODE OPTIONS **************************** */

	mode = false;
	size_t	index = 2;
	std::string message = "";

	for (size_t i = 0; args[1][i]; i++)
	{
		if (args[1][i] == '+' || args[1][i] == '-')
			mode = args[1][i++];
		switch (args[1][i])
		{
			case 'i':
				channelInviteMod(channel, mode, message);
				break;
			case 'k':
				channelKey(channel, mode, message, args, index);
				if (mode == '+')
					index++;
				break;
			case 'o':
				channelOperator(channel, mode, message, args, index);
				index++;
				break;
			case 't':
				channelTopic(channel, mode, message);
				break;
			case 'l':
				channelLimit(channel, mode, message, args, index);
				if (mode == '+')
					index++;
				break;
			case 'c':
				channelColor(channel, mode, message);
				break;
			default:
				break;
		}
	}

	sendToClient(it->first, message);
}

void	Server::channelInviteMod(Channel* channel, int mode, std::string& message){
	if (mode == '+')
	{
		channel->setInviteMode(true);
		message += MODE_INVITE_TRUE;
	}
	else if (mode == '-')
	{
		channel->setInviteMode(false);
		message += MODE_INVITE_FALSE;
	}
}

void	Server::channelKey(Channel* channel, int mode, std::string& message, std::vector<std::string> args, size_t index){
	if (mode == '+')
	{
		channel->setKey(args[index]);
		message += MODE_KEY_SET;
	}
	else if (mode == '-')
	{
		channel->setKey("");
		message += MODE_KEY_UNSET;
	}
}

void	Server::channelOperator(Channel* channel, int mode, std::string& message, std::vector<std::string> args, size_t index){
	if (channel->isClientInChannel(args[index]) == false)
		message += MODE_OP_NOT_IN_CHANNEL + args[index] + "\n";
	else if (mode == '+')
	{
		channel->setClientOpModeTo(args[index], true);
		message += MODE_OP_SET + args[index] + "\n";
	}
	else if (mode == '-')
	{
		channel->setClientOpModeTo(args[index], false);
		message += MODE_OP_UNSET + args[index] + "\n";
	}
}

void	Server::channelTopic(Channel* channel, int mode, std::string& message){
	if (mode == '+')
	{
		channel->setTopChangeMode(true);
		message += MODE_TOPIC_SET;
	}
	else if (mode == '-')
	{
		channel->setTopChangeMode(false);
		message += MODE_TOPIC_UNSET;
	}
}

void	Server::channelLimit(Channel* channel, int mode, std::string& message, std::vector<std::string> args, size_t index){
	long int	value = 0;
	char*		rest;
	std::string restString;

	if (mode == '+')
	{
		value = strtol(args[index].c_str(), &rest, 10);
		restString = rest;
		if (restString.length() != 0 || restString.empty() == false)	
		{
			message += MODE_LIMIT_WRONG_CHAR + restString + '\n';
			return;
		}
		if (args[index].size() > 11 || value > 2147483647 || value < 1)
		{
			message += MODE_LIMIT_WRONG;
			return;
		}
		channel->setUserLimit(value);
		message += MODE_LIMIT_SET + args[index] + "\n";
	}
	else if (mode == '-')
	{
		channel->setUserLimit(value);
		message += MODE_LIMIT_UNSET;
	}
}

void	Server::channelColor(Channel* channel, int mode, std::string& message)
{
	if (mode == '+')
	{
		srand (clock());
		channel->setColor("\e[48;5;" + itoa(rand()%230 + 1) + "m");
		message += MODE_COLOR_SET + channel->getColor() + "XXXXX\e[0m\n";
	}
	else if (mode == '-')
	{
		channel->setColor("\e[0m");
		message += MODE_COLOR_UNSET;
	}
}