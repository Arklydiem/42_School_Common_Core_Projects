/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_is_closed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:52:21 by argomez           #+#    #+#             */
/*   Updated: 2023/01/30 10:03:01 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
			if (datas->map[y][x] == '0')
				check_inner_map(y, x, datas);
			x++;
		}
		y++;
	}
}
