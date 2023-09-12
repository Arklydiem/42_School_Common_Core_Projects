/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 15:32:11 by argomez           #+#    #+#             */
/*   Updated: 2023/02/10 14:46:03 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	get_images(t_data *datas)
{
		datas->textures._dark[0].img = mlx_xpm_file_to_image(datas->mlx.mlx, \
			"./maps_bonus/textures/wall_plants_shadow.xpm", \
		&datas->textures._dark[0].width, &datas->textures._dark[0].height);
		datas->textures._dark[1].img = mlx_xpm_file_to_image(datas->mlx.mlx, \
			"./maps_bonus/textures/wall_plants_shadow_thunder_1.xpm", \
		&datas->textures._dark[1].width, &datas->textures._dark[1].height);
		datas->textures._dark[2].img = mlx_xpm_file_to_image(datas->mlx.mlx, \
			"./maps_bonus/textures/wall_plants_shadow_thunder_2.xpm", \
		&datas->textures._dark[2].width, &datas->textures._dark[2].height);
		datas->textures._dark[3].img = mlx_xpm_file_to_image(datas->mlx.mlx, \
			"./maps_bonus/textures/wall_plants_shadow_thunder_3.xpm", \
		&datas->textures._dark[3].width, &datas->textures._dark[3].height);
		datas->textures._dark[4].img = mlx_xpm_file_to_image(datas->mlx.mlx, \
			"./maps_bonus/textures/wall_plants_shadow_thunder_4.xpm", \
		&datas->textures._dark[4].width, &datas->textures._dark[4].height);
		datas->textures._dark[5].img = mlx_xpm_file_to_image(datas->mlx.mlx, \
			"./maps_bonus/textures/wall_plants_shadow_thunder_5.xpm", \
		&datas->textures._dark[5].width, &datas->textures._dark[5].height);
		datas->textures._dark[6].img = mlx_xpm_file_to_image(datas->mlx.mlx, \
			"./maps_bonus/textures/wall_plants_shadow_thunder_6.xpm", \
		&datas->textures._dark[6].width, &datas->textures._dark[6].height);
}

static void	get_addresses(t_data *datas)
{
	t_image	*dark;

	dark = datas->textures._dark;
	dark[0].addr = mlx_get_data_addr(dark[0].img, &dark[0].bits_per_pixel, \
		&dark[0].line_length, &dark[0].endian);
	dark[1].addr = mlx_get_data_addr(dark[1].img, &dark[1].bits_per_pixel, \
		&dark[1].line_length, &dark[1].endian);
	dark[2].addr = mlx_get_data_addr(dark[2].img, &dark[2].bits_per_pixel, \
		&dark[2].line_length, &dark[2].endian);
	dark[3].addr = mlx_get_data_addr(dark[3].img, &dark[3].bits_per_pixel, \
		&dark[3].line_length, &dark[3].endian);
	dark[4].addr = mlx_get_data_addr(dark[4].img, &dark[4].bits_per_pixel, \
		&dark[4].line_length, &dark[4].endian);
	dark[5].addr = mlx_get_data_addr(dark[5].img, &dark[5].bits_per_pixel, \
		&dark[5].line_length, &dark[5].endian);
	dark[6].addr = mlx_get_data_addr(dark[6].img, &dark[6].bits_per_pixel, \
		&dark[6].line_length, &dark[6].endian);
}

static void	get_images_light(t_data *datas)
{
		datas->textures._light[0].img = mlx_xpm_file_to_image(datas->mlx.mlx, \
			"./maps_bonus/textures/wall_plants_light.xpm", \
		&datas->textures._light[0].width, &datas->textures._light[0].height);
		datas->textures._light[1].img = mlx_xpm_file_to_image(datas->mlx.mlx, \
			"./maps_bonus/textures/wall_plants_light_thunder_1.xpm", \
		&datas->textures._light[1].width, &datas->textures._light[1].height);
		datas->textures._light[2].img = mlx_xpm_file_to_image(datas->mlx.mlx, \
			"./maps_bonus/textures/wall_plants_light_thunder_2.xpm", \
		&datas->textures._light[2].width, &datas->textures._light[2].height);
		datas->textures._light[3].img = mlx_xpm_file_to_image(datas->mlx.mlx, \
			"./maps_bonus/textures/wall_plants_light_thunder_3.xpm", \
		&datas->textures._light[3].width, &datas->textures._light[3].height);
		datas->textures._light[4].img = mlx_xpm_file_to_image(datas->mlx.mlx, \
			"./maps_bonus/textures/wall_plants_light_thunder_4.xpm", \
		&datas->textures._light[4].width, &datas->textures._light[4].height);
		datas->textures._light[5].img = mlx_xpm_file_to_image(datas->mlx.mlx, \
			"./maps_bonus/textures/wall_plants_light_thunder_5.xpm", \
		&datas->textures._light[5].width, &datas->textures._light[5].height);
		datas->textures._light[6].img = mlx_xpm_file_to_image(datas->mlx.mlx, \
			"./maps_bonus/textures/wall_plants_light_thunder_6.xpm", \
		&datas->textures._light[6].width, &datas->textures._light[6].height);
}

static void	get_addresses_light(t_data *datas)
{
	t_image	*light;

	light = datas->textures._light;
	light[0].addr = mlx_get_data_addr(light[0].img, &light[0].bits_per_pixel, \
		&light[0].line_length, &light[0].endian);
	light[1].addr = mlx_get_data_addr(light[1].img, &light[1].bits_per_pixel, \
		&light[1].line_length, &light[1].endian);
	light[2].addr = mlx_get_data_addr(light[2].img, &light[2].bits_per_pixel, \
		&light[2].line_length, &light[2].endian);
	light[3].addr = mlx_get_data_addr(light[3].img, &light[3].bits_per_pixel, \
		&light[3].line_length, &light[3].endian);
	light[4].addr = mlx_get_data_addr(light[4].img, &light[4].bits_per_pixel, \
		&light[4].line_length, &light[4].endian);
	light[5].addr = mlx_get_data_addr(light[5].img, &light[5].bits_per_pixel, \
		&light[5].line_length, &light[5].endian);
	light[6].addr = mlx_get_data_addr(light[6].img, &light[6].bits_per_pixel, \
		&light[6].line_length, &light[6].endian);
}

void	load_textures(t_data *datas)
{
	get_images(datas);
	get_images_light(datas);
	if (!check_images(datas))
		ft_error(15, 0, datas);
	get_addresses(datas);
	get_addresses_light(datas);
}
