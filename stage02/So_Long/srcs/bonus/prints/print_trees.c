/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_trees.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:06:20 by argomez           #+#    #+#             */
/*   Updated: 2022/06/06 11:21:17 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	print_trees(t_game *g, int y, int x)
{
	t_img	*w;
	int		random;

	w = g->w;
	random = (int)(rand() / (double)RAND_MAX * (4 - 1));
	if (random == 0)
		mlx_put_image_to_window(g->mlx->m, g->mlx->w, w[8].i, x * 64, y * 64);
	else if (random == 1)
		mlx_put_image_to_window(g->mlx->m, g->mlx->w, w[9].i, x * 64, y * 64);
	else if (random == 2)
		mlx_put_image_to_window(g->mlx->m, g->mlx->w, w[10].i, x * 64, y * 64);
	else if (random == 3)
		mlx_put_image_to_window(g->mlx->m, g->mlx->w, w[11].i, x * 64, y * 64);
}
