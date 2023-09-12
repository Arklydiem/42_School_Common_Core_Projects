/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_doors_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 15:24:50 by argomez           #+#    #+#             */
/*   Updated: 2023/02/10 14:46:48 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static int	check_placement(int y, int x, t_data *datas)
{
	char	**map;

	map = datas->map;
	if (map[y][x - 1] == '1' && map[y][x + 1] == '1')
		return (1);
	if (map[y - 1][x] == '1' && map[y + 1][x] == '1')
		return (1);
	return (0);
}

void	check_doors(int y, int x, t_data *datas)
{
	if (!check_placement(y, x, datas))
		ft_error(14, 0, datas);
}
