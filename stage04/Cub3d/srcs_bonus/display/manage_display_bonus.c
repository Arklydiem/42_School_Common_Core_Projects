/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_display_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 10:39:57 by argomez           #+#    #+#             */
/*   Updated: 2023/02/10 14:46:07 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	ray_direction(int i, t_data *datas)
{
	double	camera_x;
	double	width;

	width = (double)WIDTH;
	camera_x = ((2 * i) / width) - 1;
	if (datas->start == 'N' || datas->start == 'E')
	{
		datas->_ray.x = datas->_player.x + datas->plane.x * camera_x;
		datas->_ray.y = datas->_player.y + datas->plane.y * camera_x;
	}
	else if (datas->start == 'S' || datas->start == 'W' )
	{
		datas->_ray.x = datas->_player.x - datas->plane.x * camera_x;
		datas->_ray.y = datas->_player.y - datas->plane.y * camera_x;
	}
}

static void	get_render(double perp_wall_dist, t_data *datas)
{
	int		start_draw_wall;
	int		end_draw_wall;
	int		wall_height;
	t_image	texture;

	wall_height = (int)(HEIGHT / perp_wall_dist);
	datas->wall_height = wall_height;
	start_draw_wall = HEIGHT * 0.5 - wall_height * 0.5;
	if (start_draw_wall < 0)
		start_draw_wall = 0;
	end_draw_wall = wall_height * 0.5 + HEIGHT * 0.5;
	if (end_draw_wall >= HEIGHT)
		end_draw_wall = HEIGHT - 1;
	texture = find_texture(datas, datas->side);
	fill_column(start_draw_wall, end_draw_wall, datas, &texture);
}

static void	calcul_wall_hit(double delta_dist_x_y[2], double *step_dist_x,
	double *step_dist_y, t_data *datas)
{
	datas->hit = 0;
	while (datas->hit == 0)
	{
		if (step_dist_x[1] < step_dist_y[1])
		{
			step_dist_x[1] += delta_dist_x_y[0];
			datas->tile.x += step_dist_x[0];
			datas->side = 0;
		}
		else
		{
			step_dist_y[1] += delta_dist_x_y[1];
			datas->tile.y += step_dist_y[0];
			datas->side = 1;
		}
		if (datas->map[datas->tile.y][datas->tile.x] == '1')
			datas->hit = 1;
		else if (datas->map[datas->tile.y][datas->tile.x] == 'C')
			datas->hit = 2;
	}
	datas->perp_wall_dist = calcul_perp_wall_dist(datas->side, step_dist_x, \
		step_dist_y, delta_dist_x_y);
	get_render(datas->perp_wall_dist, datas);
}

void	manage_render(t_data *datas)
{
	double	delta_dist_x_y[2];
	double	*step_dist_x;
	double	*step_dist_y;

	datas->x_count = 0;
	while (datas->x_count < WIDTH)
	{
		ray_direction(datas->x_count, datas);
		datas->tile.x = floor(datas->player.x);
		datas->tile.y = floor(datas->player.y);
		delta_dist_x_y[0] = calcul_delta_dist_x(datas);
		delta_dist_x_y[1] = calcul_delta_dist_y(datas);
		step_dist_x = calculate_step_dist_x(delta_dist_x_y[0], datas);
		step_dist_y = calculate_step_dist_y(delta_dist_x_y[1], datas);
		calcul_wall_hit(delta_dist_x_y, step_dist_x, step_dist_y, datas);
		free_step_dist(step_dist_x, step_dist_y);
		datas->x_count++;
	}
	display_minimap(datas);
	mlx_put_image_to_window(datas->mlx.mlx, \
		datas->mlx.window, datas->screen.img, 0, 0);
}

void	manage_display(t_data *datas)
{
	t_mlx	*mlx;
	t_image	*screen;

	mlx = &datas->mlx;
	screen = &datas->screen;
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		ft_error(12, 0, datas);
	mlx->window = mlx_new_window(mlx->mlx, WIDTH, HEIGHT, NAME);
	if (!mlx->window)
		ft_error(12, 0, datas);
	screen->img = mlx_new_image(mlx->mlx, WIDTH, HEIGHT);
	screen->addr = mlx_get_data_addr(screen->img, &screen->bits_per_pixel, \
		&screen->line_length, &screen->endian);
	load_textures(datas);
	set_coordinates(datas);
	define_base_colors(datas);
	mlx_mouse_hide(mlx->mlx, mlx->window);
	mlx_mouse_move(mlx->mlx, mlx->window, WIDTH / 2, HEIGHT / 2);
	mlx_loop_hook(mlx->mlx, frame_rate, datas);
	mlx_hook(mlx->window, 2, 1L, manage_keys, datas);
	mlx_hook(mlx->window, DestroyNotify, StructureNotifyMask, exit_game, datas);
	mlx_loop(mlx->mlx);
}
