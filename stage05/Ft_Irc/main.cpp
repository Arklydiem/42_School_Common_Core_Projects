/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 10:07:18 by vnadal            #+#    #+#             */
/*   Updated: 2023/05/29 16:08:57 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

void	handleSignal(int sig)
{
	(void)sig;
}

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		Error::printError(ERR_ARGS);
		return (1);
	}
	std::signal(SIGINT, &handleSignal);

	Server *server = new Server(argv[1], argv[2]);
	server->printBanner(-1);
	server->run();
	delete server;
}