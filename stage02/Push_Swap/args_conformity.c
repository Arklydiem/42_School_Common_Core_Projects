/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_conformity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:07:17 by argomez           #+#    #+#             */
/*   Updated: 2022/07/16 15:48:50 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	check_char(char *str, int index)
{
	char	*tab;
	int		i;

	tab = "0123456789- ";
	i = 0;
	while (i < 12)
	{
		if (str[index] == tab[i])
		{
			if (str[index] != ' ' && str[index + 1] == '-')
				return (0);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	check_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (check_char(str, i) == 0)
			return (0);
		i++;
	}
	return (1);
}

void	args_conformity(t_tabs *tabs, int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (check_string(argv[i]) == 0)
			ft_error(tabs);
		i++;
	}
}
