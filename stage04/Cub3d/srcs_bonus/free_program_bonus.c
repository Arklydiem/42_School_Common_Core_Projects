/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_program_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:07:30 by vnadal            #+#    #+#             */
/*   Updated: 2023/02/10 14:47:30 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map && map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static void	free_texture(t_texture *texture)
{
	int	i;

	i = 0;
	while (texture->ceiling && texture->ceiling[i])
	{
		free(texture->ceiling[i]);
		i++;
	}
	free(texture->ceiling);
	i = 0;
	while (texture->floor && texture->floor[i])
	{
		free(texture->floor[i]);
		i++;
	}
	free(texture->floor);
}

static void	destroy_images(t_data *datas)
{
	t_image	*light;
	t_image	*dark;
	int		i;

	if (!datas->mlx.mlx)
		return ;
	light = datas->textures._light;
	dark = datas->textures._dark;
	i = 0;
	while (i < 7)
	{
		if (light[i].img)
			mlx_destroy_image(datas->mlx.mlx, light[i].img);
		if (dark[i].img)
			mlx_destroy_image(datas->mlx.mlx, dark[i].img);
		i++;
	}
}

static void	free_mlx(t_mlx *mlx, t_image *screen)
{
	if (!mlx->mlx)
		return ;
	mlx_clear_window(mlx->mlx, mlx->window);
	mlx_destroy_window(mlx->mlx, mlx->window);
	mlx_destroy_image(mlx->mlx, screen->img);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
}

void	free_program(t_data *datas)
{
	free_map(datas->map);
	free_texture(&datas->textures);
	destroy_images(datas);
	free_mlx(&datas->mlx, &datas->screen);
	exit(0);
}
