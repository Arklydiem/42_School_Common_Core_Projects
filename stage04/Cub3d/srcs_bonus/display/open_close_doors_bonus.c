/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close_doors_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:37:24 by argomez           #+#    #+#             */
/*   Updated: 2023/02/10 14:46:20 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	swap_symbol(char c, int y, int x, t_data *datas)
{
	if (c == 'C')
		datas->map[y][x] = 'O';
	else if (c == 'O')
		datas->map[y][x] = 'C';
}

static void	check_upper_line(int x, int y, t_data *datas)
{
	char	**map;

	map = datas->map;
	if (map[y - 1][x - 1] == 'C' || map[y - 1][x - 1] == 'O')
		swap_symbol(map[y - 1][x - 1], y - 1, x - 1, datas);
	else if (map[y - 1][x] == 'C' || map[y - 1][x] == 'O')
		swap_symbol(map[y - 1][x], y - 1, x, datas);
	else if (map[y - 1][x + 1] == 'C' || map[y - 1][x + 1] == 'O')
		swap_symbol(map[y - 1][x + 1], y - 1, x + 1, datas);
}

static void	check_line(int x, int y, t_data *datas)
{
	char	**map;

	map = datas->map;
	if (map[y][x - 1] == 'C' || map[y][x - 1] == 'O')
		swap_symbol(map[y][x - 1], y, x - 1, datas);
	else if (map[y][x + 1] == 'C' || map[y][x + 1] == 'O')
		swap_symbol(map[y][x + 1], y, x + 1, datas);
}

static void	check_lower_line(int x, int y, t_data *datas)
{
	char	**map;

	map = datas->map;
	if (map[y + 1][x - 1] == 'C' || map[y + 1][x - 1] == 'O')
		swap_symbol(map[y + 1][x - 1], y + 1, x - 1, datas);
	else if (map[y + 1][x] == 'C' || map[y + 1][x] == 'O')
		swap_symbol(map[y + 1][x], y + 1, x, datas);
	else if (map[y + 1][x + 1] == 'C' || map[y + 1][x + 1] == 'O')
		swap_symbol(map[y + 1][x + 1], y + 1, x + 1, datas);
}

void	open_close_doors(t_data *datas)
{
	int	x;
	int	y;

	x = floor(datas->player.x);
	y = floor(datas->player.y);
	check_upper_line(x, y, datas);
	check_line(x, y, datas);
	check_lower_line(x, y, datas);
}
