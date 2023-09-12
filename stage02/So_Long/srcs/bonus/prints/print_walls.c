/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:52:18 by argomez           #+#    #+#             */
/*   Updated: 2022/06/07 15:47:46 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	print_walls(t_game *g, int y, int x)
{
	t_img	*w;

	w = g->w;
	if (y == 1 && x == 1)
		mlx_put_image_to_window(g->mlx->m, g->mlx->w, w[0].i, x * 64, y * 64);
	else if (y == 1 && x == g->map->x)
		mlx_put_image_to_window(g->mlx->m, g->mlx->w, w[1].i, x * 64, y * 64);
	else if (y == g->map->y && x == 1)
		mlx_put_image_to_window(g->mlx->m, g->mlx->w, w[2].i, x * 64, y * 64);
	else if (y == g->map->y && x == g->map->x)
		mlx_put_image_to_window(g->mlx->m, g->mlx->w, w[3].i, x * 64, y * 64);
	else if (y == 1)
		mlx_put_image_to_window(g->mlx->m, g->mlx->w, w[4].i, x * 64, y * 64);
	else if (y == g->map->y)
		mlx_put_image_to_window(g->mlx->m, g->mlx->w, w[7].i, x * 64, y * 64);
	else if (x == 1)
		mlx_put_image_to_window(g->mlx->m, g->mlx->w, w[5].i, x * 64, y * 64);
	else if (x == g->map->x)
		mlx_put_image_to_window(g->mlx->m, g->mlx->w, w[6].i, x * 64, y * 64);
	else
		print_trees(g, y, x);
}
