/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 18:06:21 by argomez           #+#    #+#             */
/*   Updated: 2022/07/16 16:50:48 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	check_atoi(t_tabs *tabs, char *arg)
{
	if (ft_strchrc(arg, '-') == 1 && ft_strlen(arg) > 11)
		ft_error(tabs);
	else if (ft_strchrc(arg, '-') == 0 && ft_strlen(arg) > 10)
		ft_error(tabs);
}

static void	add_multiples(t_tabs *tabs, const char *arg)
{
	char	**args;
	int		i;

	args = ft_split(arg, ' ');
	i = -1;
	while (args[++i] != NULL)
	{
		check_atoi(tabs, args[i]);
		tabs->a[tabs->count] = (long int)ft_atoi(args[i]);
		if (tabs->a[tabs->count] == 0
			&& args[i][0] == '-' && args[i][1] == '0');
		else if (tabs->a[tabs->count] == 0 && (args[i][0] != '0'))
		{
			free(args[i]);
			while (args[++i] != NULL)
				free(args[i]);
			free(args);
			ft_error(tabs);
		}
		tabs->count++;
		free(args[i]);
	}
	free(args);
}

void	fill_tab(t_tabs *tabs, int argc, char **argv)
{
	int	i;

	tabs->a = ft_calloc(sizeof(long int), tabs->size + 1);
	tabs->b = ft_calloc(sizeof(long int), tabs->size + 1);
	if (tabs->a == NULL || tabs->b == NULL)
		ft_error(tabs);
	i = 1;
	while (i < argc)
	{
		if (ft_strchrc(argv[i], ' ') == 1)
			add_multiples(tabs, argv[i]);
		else
		{
			check_atoi(tabs, argv[i]);
			tabs->a[tabs->count] = (long int)ft_atoi(argv[i]);
			if (tabs->a[tabs->count] == 0
				&& argv[i][0] == '-' && argv[i][1] == '0');
			else if (argv[i][0] != '0' && tabs->a[tabs->count] == 0)
				ft_error(tabs);
			tabs->count++;
		}
		i++;
	}
	tabs->count = 0;
}
