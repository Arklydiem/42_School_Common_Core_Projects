/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:32:11 by argomez           #+#    #+#             */
/*   Updated: 2023/02/06 15:17:59 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	get_images(t_data *datas)
{
	t_texture	*textures;
	t_image		*n_wall;
	t_image		*s_wall;
	t_image		*e_wall;
	t_image		*w_wall;

	textures = &datas->textures;
	n_wall = &textures->n_wall;
	s_wall = &textures->s_wall;
	w_wall = &textures->w_wall;
	e_wall = &textures->e_wall;
	n_wall->img = mlx_xpm_file_to_image(datas->mlx.mlx, datas->textures.north, \
		&n_wall->width, &n_wall->height);
	s_wall->img = mlx_xpm_file_to_image(datas->mlx.mlx, datas->textures.south, \
		&s_wall->width, &s_wall->height);
	w_wall->img = mlx_xpm_file_to_image(datas->mlx.mlx, datas->textures.west, \
		&w_wall->width, &w_wall->height);
	e_wall->img = mlx_xpm_file_to_image(datas->mlx.mlx, datas->textures.east, \
		&e_wall->width, &e_wall->height);
}

static void	get_addresses(t_data *datas)
{
	t_texture	*textures;
	t_image		*n_wall;
	t_image		*s_wall;
	t_image		*e_wall;
	t_image		*w_wall;

	textures = &datas->textures;
	n_wall = &textures->n_wall;
	s_wall = &textures->s_wall;
	w_wall = &textures->w_wall;
	e_wall = &textures->e_wall;
	n_wall->addr = mlx_get_data_addr(n_wall->img, &n_wall->bits_per_pixel, \
		&n_wall->line_length, &n_wall->endian);
	s_wall->addr = mlx_get_data_addr(s_wall->img, &s_wall->bits_per_pixel, \
		&s_wall->line_length, &s_wall->endian);
	w_wall->addr = mlx_get_data_addr(w_wall->img, &w_wall->bits_per_pixel, \
		&w_wall->line_length, &w_wall->endian);
	e_wall->addr = mlx_get_data_addr(e_wall->img, &e_wall->bits_per_pixel, \
		&e_wall->line_length, &e_wall->endian);
}

void	load_textures(t_data *datas)
{
	t_texture	*textures;
	t_image		*n_wall;
	t_image		*s_wall;
	t_image		*e_wall;
	t_image		*w_wall;

	textures = &datas->textures;
	n_wall = &textures->n_wall;
	s_wall = &textures->s_wall;
	w_wall = &textures->w_wall;
	e_wall = &textures->e_wall;
	get_images(datas);
	if (!n_wall->img || !s_wall->img || !w_wall->img || !e_wall->img)
		ft_error(13, 0, datas);
	get_addresses(datas);
	if (!n_wall->addr || !s_wall->addr || !w_wall->addr || !e_wall->addr)
		ft_error(13, 0, datas);
}
