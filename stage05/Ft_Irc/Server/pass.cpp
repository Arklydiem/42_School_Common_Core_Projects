/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pass.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 09:56:19 by vnadal            #+#    #+#             */
/*   Updated: 2023/05/11 12:22:18 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_irc.h"

int	Server::passCmd(std::map<int, Client*>::iterator it, std::vector<std::string> args)
{
	if (it->second->getClientStatus() >= LOGGED)
	{
		sendToClient(it->first, PASS_ALREADY_LOGGED);
		return (0);
	}
	if (args.size() != 1 || _password.compare(args[0]) != 0)
	{
		sendToClient(it->first, PASS_WRONG);
		if (it->second->getPasswordTries()++ > 1)
		{
			disconnectClient(it->first);
			return (FAIL);
		}
		sendToClient(it->first, PASS_TRIES + itoa(3 - it->second->getPasswordTries()) + "\n");
		return (0);
	}
	printServer("Client " + getClientInColor(it->first) + " Logged.");
	sendToClient(it->first, PASS_LOGGED);
	it->second->setClientStatus(LOGGED);
	return (0);
}