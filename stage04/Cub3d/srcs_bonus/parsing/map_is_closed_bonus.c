/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_closed_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:52:21 by argomez           #+#    #+#             */
/*   Updated: 2023/02/10 14:46:38 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	map_is_closed(t_data *datas)
{
	int	y;
	int	x;

	y = 0;
	while (datas->map[y])
	{
		x = 0;
		while (datas->map[y][x])
		{
			if (datas->map[y][x] == ' ')
				check_arround_spaces(y, x, datas);
			if (datas->map[y][x] == '0' || datas->map[y][x] == 'C')
				check_inner_map(y, x, datas);
			if (datas->map[y][x] == 'C')
				check_doors(y, x, datas);
			x++;
		}
		y++;
	}
}
