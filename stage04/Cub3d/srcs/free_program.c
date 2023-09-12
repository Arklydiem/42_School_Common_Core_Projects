/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:07:30 by vnadal            #+#    #+#             */
/*   Updated: 2023/02/09 14:00:14 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_map(char **map)
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

void	free_texture(t_texture *texture)
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
	free(texture->north);
	free(texture->south);
	free(texture->east);
	free(texture->west);
}

void	destroy_images(t_texture *textures, t_data *datas)
{
	if (textures->n_wall.img)
		mlx_destroy_image(datas->mlx.mlx, textures->n_wall.img);
	if (textures->s_wall.img)
		mlx_destroy_image(datas->mlx.mlx, textures->s_wall.img);
	if (textures->w_wall.img)
		mlx_destroy_image(datas->mlx.mlx, textures->w_wall.img);
	if (textures->e_wall.img)
		mlx_destroy_image(datas->mlx.mlx, textures->e_wall.img);
}

void	free_mlx(t_mlx *mlx, t_image *screen)
{
	if (!mlx->mlx)
		return ;
	if (mlx->window)
	{
		mlx_clear_window(mlx->mlx, mlx->window);
		mlx_destroy_window(mlx->mlx, mlx->window);
	}
	if (screen && screen->img)
		mlx_destroy_image(mlx->mlx, screen->img);
	mlx_destroy_display(mlx->mlx);
	free(mlx->mlx);
}

void	free_program(t_data *datas)
{
	free_map(datas->map);
	free_texture(&datas->textures);
	destroy_images(&datas->textures, datas);
	free_mlx(&datas->mlx, &datas->screen);
	exit(0);
}
