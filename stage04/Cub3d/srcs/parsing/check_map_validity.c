/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_validity.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:13:10 by argomez           #+#    #+#             */
/*   Updated: 2023/02/10 14:35:20 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	check_symbols_in_map(int y, int x, char c, t_data *datas)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		if (datas->player.x != -1)
			ft_error(8, 0, datas);
		datas->player.x = x;
		datas->player.y = y;
		datas->start = c;
		datas->map[y][x] = '0';
	}
	else if (!(c == '0' || c == '1' || c == ' '))
		ft_error(9, 0, datas);
}

void	check_map_validity(t_data *datas)
{
	int		y;
	int		x;

	y = 0;
	while (datas->map[y])
	{
		x = 0;
		while (datas->map[y][x])
		{
			check_symbols_in_map(y, x, datas->map[y][x], datas);
			x++;
		}
		y++;
	}
	map_is_closed(datas);
}
