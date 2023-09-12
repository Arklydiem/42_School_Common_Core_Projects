/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_colors_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:48:36 by vnadal            #+#    #+#             */
/*   Updated: 2023/02/10 14:45:55 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static unsigned int	get_color(t_image *texture, int x, int y)
{
	char	*dst;

	dst = texture->addr + (y * texture->line_length \
		+ x * (texture->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

static void	get_texture_x(int side, t_image *texture, t_data *datas)
{
	double	wall_x;

	if (side == 0)
		wall_x = datas->player.y + datas->perp_wall_dist * datas->_ray.y;
	else
		wall_x = datas->player.x + datas->perp_wall_dist * datas->_ray.x;
	wall_x -= floor((wall_x));
	datas->texture_x = (int)(wall_x * (double)(texture->width));
	if (side == 0 && datas->_ray.x > 0)
		datas->texture_x = texture->width - datas->texture_x - 1;
	if (side == 1 && datas->_ray.y < 0)
		datas->texture_x = texture->width - datas->texture_x - 1;
}

void	fill_column(int start, int end, t_data *datas, t_image *tex)
{
	int				y;
	char			*pixel;
	t_image			*screen;
	double			step;
	unsigned int	color;

	get_texture_x(datas->side, tex, datas);
	step = 1.0 * tex->height / (datas->wall_height);
	datas->texture_pos = (start - HEIGHT * 0.5 \
		+ (datas->wall_height) * 0.5) * step;
	y = start;
	screen = &datas->screen;
	while (y < end)
	{
		datas->texture_y = (int)datas->texture_pos & (tex->height - 1);
		pixel = screen->addr + (y * screen->line_length + datas->x_count \
			* (screen->bits_per_pixel / 8));
		color = get_color(tex, datas->texture_x, datas->texture_y);
		*(unsigned int *)pixel = color;
		datas->texture_pos += step;
		y++;
	}
}

static void	fill_up(t_data *datas)
{
	t_image	*screen;
	char	*pixel;
	int		y;
	int		x;

	screen = &datas->screen;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel = screen->addr + (y * screen->line_length \
					+ x * (screen->bits_per_pixel / 8));
			*(unsigned int *)pixel = datas->textures.ceiling_color;
			x++;
		}
		y++;
	}
}

void	fill_base(t_data *datas)
{
	char	*pixel;
	int		y;
	int		x;
	t_image	*screen;

	fill_up(datas);
	screen = &datas->screen;
	y = HEIGHT / 2;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel = screen->addr + (y * screen->line_length \
					+ x * (screen->bits_per_pixel / 8));
			*(unsigned int *)pixel = datas->textures.floor_color;
			x++;
		}
		y++;
	}
}
