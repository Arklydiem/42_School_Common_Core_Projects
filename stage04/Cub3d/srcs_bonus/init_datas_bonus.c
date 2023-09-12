/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_datas_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:45:44 by argomez           #+#    #+#             */
/*   Updated: 2023/02/10 14:47:36 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./cub3d_bonus.h"

static void	init_mlx(t_data *datas)
{
	datas->mlx.mlx = NULL;
	datas->mlx.window = NULL;
}

static void	init_coordinates(t_data *datas)
{
	datas->plane.x = 0;
	datas->plane.y = 0;
	datas->player.x = -1;
	datas->player.y = -1;
	datas->_player.x = 0;
	datas->_player.y = 0;
	datas->_ray.x = 0;
	datas->_ray.y = 0;
}

static void	init_screen(t_data *datas)
{
	datas->screen.addr = NULL;
	datas->screen.bits_per_pixel = 0;
	datas->screen.endian = 0;
	datas->screen.img = NULL;
	datas->screen.line_length = 0;
}

static void	init_textures(t_data *datas)
{
	datas->textures.ceiling = NULL;
	datas->textures.floor = NULL;
}

void	init_datas(t_data *datas)
{
	datas->map = NULL;
	datas->x_count = 0;
	datas->perp_wall_dist = 0;
	datas->wall_height = 0;
	datas->texture_pos = 0;
	datas->texture_x = 0;
	datas->texture_y = 0;
	datas->side = 0;
	datas->animation = 0;
	init_mlx(datas);
	init_coordinates(datas);
	init_screen(datas);
	init_textures(datas);
}
