/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inner_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 12:58:39 by argomez           #+#    #+#             */
/*   Updated: 2023/01/27 15:47:50 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	check_borders(int y, int x, t_data *datas)
{
	if (x == 0 || x == ft_strlen(datas->map[y]) - 1)
		ft_error(10, 0, datas);
	if (y == 0 || !datas->map[y + 1])
		ft_error(10, 0, datas);
}

static void	check_upper_line(int y, int x, t_data *datas)
{
	if (x != 0 && !datas->map[y - 1][x - 1])
		ft_error(10, 0, datas);
	if (x != 0 && !datas->map[y - 1][x])
		ft_error(10, 0, datas);
	if (x != 0 && !datas->map[y - 1][x + 1])
		ft_error(10, 0, datas);
}

static void	check_lower_line(int y, int x, t_data *datas)
{
	if (x != 0 && !datas->map[y + 1][x - 1])
		ft_error(10, 0, datas);
	if (x != 0 && !datas->map[y + 1][x])
		ft_error(10, 0, datas);
	if (x != 0 && !datas->map[y + 1][x + 1])
		ft_error(10, 0, datas);
}

void	check_inner_map(int y, int x, t_data *datas)
{
	check_borders(y, x, datas);
	if (y != 0 && datas->map[y + 1])
	{
		check_upper_line(y, x, datas);
		check_lower_line(y, x, datas);
	}
	else if (y != 0)
		check_upper_line(y, x, datas);
	else
		check_lower_line(y, x, datas);
}
