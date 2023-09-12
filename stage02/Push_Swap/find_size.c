/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 20:03:41 by argomez           #+#    #+#             */
/*   Updated: 2022/06/27 16:47:23 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	check_multiples(t_tabs *tabs, const char *arg)
{
	char	**args;
	int		i;

	args = ft_split(arg, ' ');
	i = -1;
	while (args[++i] != NULL)
	{
		tabs->size++;
		free(args[i]);
	}
	free(args);
}

void	find_size(t_tabs *tabs, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_strchrc(argv[i], ' ') == 1)
			check_multiples(tabs, argv[i]);
		else
			tabs->size++;
		i++;
	}
	tabs->size_a = tabs->size;
}
