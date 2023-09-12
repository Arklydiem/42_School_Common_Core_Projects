/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:37:30 by argomez           #+#    #+#             */
/*   Updated: 2022/08/18 17:50:20 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	main(void)
{
	struct sigaction	sa;

	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = signals_handler;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("PID = %d\n", getpid());
	signals_handler(0, NULL, NULL);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
	{
		write(2, "Signal Error\n", 7);
		return (0);
	}
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
	{
		write(2, "Signal Error\n", 7);
		return (0);
	}
	while (1)
		continue ;
	return (0);
}
