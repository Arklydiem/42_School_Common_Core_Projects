/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:37:30 by argomez           #+#    #+#             */
/*   Updated: 2022/08/19 18:15:06 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static void	validate_recive(int key)
{
	if (key == SIGUSR2)
		exit(0);
}

static void	send_binary_of(int pid, int c)
{
	int	byte;

	byte = 7;
	while (byte >= 0)
	{
		if (!(c & (1 << byte)) == 0)
			kill(pid, SIGUSR2);
		else if ((!(c & (1 << byte))) == 1)
			kill(pid, SIGUSR1);
		usleep(1);
		byte--;
	}
}

int	main(int argc, char **argv)
{
	int		i;
	int		pid;
	char	*size;

	if (argc < 3)
		return (0);
	signal(SIGUSR2, validate_recive);
	pid = ft_atoi(argv[1]);
	size = ft_itoa(ft_strlen(argv[2]));
	send_binary_of(pid, 0);
	i = -1;
	while (size[++i])
		send_binary_of(pid, size[i]);
	send_binary_of(pid, 0);
	i = -1;
	while (argv[2][++i])
		send_binary_of(pid, argv[2][i]);
	send_binary_of(pid, 0);
	while (1)
		continue ;
	return (0);
}
