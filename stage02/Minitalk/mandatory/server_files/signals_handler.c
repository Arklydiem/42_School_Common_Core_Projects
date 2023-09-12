/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_handler.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 14:55:15 by argomez           #+#    #+#             */
/*   Updated: 2022/08/18 17:56:03 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static void	print_and_initialise_again(t_data *datas, siginfo_t *infos)
{
	datas->str_to_print[++datas->index_str] = '\0';
	ft_printf("%s", datas->str_to_print);
	free(datas->str_to_print);
	initialise_datas(datas);
	kill(infos->si_pid, SIGUSR2);
	infos->si_pid = 0;
}

static void	fill_str_to_print(t_data *datas)
{
	if (datas->value == 0)
	{
		datas->str_to_print = malloc((datas->size_of_str + 10) * sizeof(char));
	}
	else
	{
		datas->str_to_print[++datas->index_str] = datas->value;
	}
}

static void	find_size(t_data *datas)
{
	datas->size_of_str *= 10;
	datas->size_of_str += (datas->value - 48);
}

static void	check_binary(t_data *datas)
{
	datas->index_binaries_tab = 0;
	datas->value = (int)ft_btod(datas->binaries_tab);
	if (datas->value == 0)
		datas->signals_zero_number++;
}

void	signals_handler(int key, siginfo_t *infos, void *context)
{
	static t_data	datas;

	(void)context;
	if (key == 0)
		initialise_datas(&datas);
	else
	{
		if (key == SIGUSR1)
			datas.binaries_tab[datas.index_binaries_tab++] = 0;
		else if (key == SIGUSR2)
			datas.binaries_tab[datas.index_binaries_tab++] = 1;
		if (datas.index_binaries_tab == 8)
		{
			check_binary(&datas);
			if (datas.signals_zero_number == 1 && datas.value != 0)
				find_size(&datas);
			else if (datas.signals_zero_number == 2)
				fill_str_to_print(&datas);
			else if (datas.signals_zero_number == 3)
				print_and_initialise_again(&datas, infos);
		}
	}
}
