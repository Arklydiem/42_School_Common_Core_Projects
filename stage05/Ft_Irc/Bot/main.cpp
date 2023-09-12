/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 11:23:50 by argomez           #+#    #+#             */
/*   Updated: 2023/05/29 16:04:34 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bot.hpp"

int main(int argc, char const* argv[])
{
	if (argc != 3 && argc != 4)
	{
		return (-1);
	}
	
	if (argc == 3)
	{
		Bot	bot(atoi(argv[1]), argv[2]);
		bot.run();
	}	
	else if (argc == 4)
	{
		Bot	bot(atoi(argv[1]), argv[2], argv[3]);
		bot.run();
	}
}
