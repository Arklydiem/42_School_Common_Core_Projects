/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arround_spaces_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 11:58:31 by argomez           #+#    #+#             */
/*   Updated: 2023/02/10 14:46:43 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	upper_line(int y, int x, t_data *datas)
{
	if (x != 0 && x < ft_strlen(datas->map[y - 1]))
	{
		if (datas->map[y - 1][x - 1] != ' '
			&& datas->map[y - 1][x - 1] != '1')
			ft_error(10, 0, datas);
	}
	if (x < ft_strlen(datas->map[y - 1]) && datas->map[y - 1][x])
	{
		if (datas->map[y - 1][x] != ' ' && datas->map[y - 1][x] != '1')
			ft_error(10, 0, datas);
	}
	if (x < ft_strlen(datas->map[y - 1]) && datas->map[y - 1][x + 1])
	{
		if (datas->map[y - 1][x + 1] != ' '
			&& datas->map[y - 1][x + 1] != '1')
			ft_error(10, 0, datas);
	}
}

static void	actual_line(int y, int x, t_data *datas)
{
	if (x != 0)
	{
		if (datas->map[y][x - 1] != ' ' && datas->map[y][x - 1] != '1')
			ft_error(10, 0, datas);
	}
	if (x != ft_strlen(datas->map[y]) - 1)
	{
		if (datas->map[y][x + 1] != ' ' && datas->map[y][x + 1] != '1')
			ft_error(10, 0, datas);
	}
}

static void	lower_line(int y, int x, t_data *datas)
{
	if (x != 0 && x < ft_strlen(datas->map[y + 1]))
	{
		if (datas->map[y + 1][x - 1] != ' '
			&& datas->map[y + 1][x - 1] != '1')
			ft_error(10, 0, datas);
	}
	if (x < ft_strlen(datas->map[y + 1]) && datas->map[y + 1][x])
	{
		if (datas->map[y + 1][x] != ' ' && datas->map[y + 1][x] != '1')
			ft_error(10, 0, datas);
	}
	if (x < ft_strlen(datas->map[y + 1]) && datas->map[y + 1][x + 1])
	{
		if (datas->map[y + 1][x + 1] != ' '
			&& datas->map[y + 1][x + 1] != '1')
			ft_error(10, 0, datas);
	}
}

void	check_arround_spaces(int y, int x, t_data *datas)
{
	if (y != 0 && datas->map[y + 1])
	{
		upper_line(y, x, datas);
		actual_line(y, x, datas);
		lower_line(y, x, datas);
	}
	else if (y == 0)
	{
		actual_line(y, x, datas);
		lower_line(y, x, datas);
	}
	else if (!datas->map[y + 1])
	{
		upper_line(y, x, datas);
		actual_line(y, x, datas);
	}
}
