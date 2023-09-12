/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_mini_map_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 09:48:43 by vnadal            #+#    #+#             */
/*   Updated: 2023/02/10 14:45:57 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	display_black_behind(t_data *datas)
{
	char	*pixel;
	int		x;
	int		y;

	y = 0;
	while (y < 180)
	{
		x = WIDTH;
		while (x > (WIDTH - 180))
		{
			pixel = datas->screen.addr + (y * datas->screen.line_length \
					+ x * (datas->screen.bits_per_pixel / 8));
			*(unsigned int *)pixel = 0x0000;
			x--;
		}
		y++;
	}
}

static void	display_player(t_data *datas)
{
	char	*pixel;
	int		x;
	int		y;

	y = 85;
	while (y < 95)
	{
		x = WIDTH - 95;
		while (x < (WIDTH - 85))
		{
			pixel = datas->screen.addr + (y * datas->screen.line_length \
					+ x * (datas->screen.bits_per_pixel / 8));
			*(unsigned int *)pixel = 0xff0000;
			x++;
		}
		y++;
	}
}

static void	print_wall(t_data *datas, int y, int x)
{
	int		start_y;
	int		start_x;
	int		tmp;
	char	*pixel;

	y = y - floor(datas->player.y);
	y = (80 + (20 * y));
	start_y = y;
	tmp = x;
	while (y < (start_y + 20))
	{
		x = tmp - floor(datas->player.x);
		x = (WIDTH - 100) + (20 * x);
		start_x = x;
		while (x < start_x + 20)
		{
			pixel = datas->screen.addr + (y * datas->screen.line_length \
					+ x * (datas->screen.bits_per_pixel / 8));
			*(unsigned int *)pixel = 0xffffff;
			x++;
		}
		y++;
	}
}

static void	display_walls(t_data *datas)
{
	int	x;
	int	y;
	int	len;
	int	max_line;

	max_line = get_max_line(datas->map);
	y = floor(datas->player.y) - 4;
	while (y < (floor(datas->player.y) + 5))
	{
		if (y >= 0 && y < max_line)
			len = ft_strlen(datas->map[y]);
		x = floor(datas->player.x) - 4;
		while (x < (floor(datas->player.x) + 5))
		{
			if (y >= 0 && y < max_line && x >= 0
				&& x < len && datas->map[y][x] == '1')
				print_wall(datas, y, x);
			x++;
		}
		y++;
	}
}

void	display_minimap(t_data *datas)
{
	display_black_behind(datas);
	display_walls(datas);
	display_player(datas);
	display_player_direction(datas);
}
