/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_collects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:26:52 by argomez           #+#    #+#             */
/*   Updated: 2022/06/07 15:46:19 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	print_collects(t_game *g, int y, int x, char p)
{
	t_img	*c;

	c = g->c;
	if (p == 60)
		mlx_put_image_to_window(g->mlx->m, g->mlx->w, c[0].i, x * 64, y * 64);
	else if (p == 61)
		mlx_put_image_to_window(g->mlx->m, g->mlx->w, c[1].i, x * 64, y * 64);
	else if (p == 62)
		mlx_put_image_to_window(g->mlx->m, g->mlx->w, c[2].i, x * 64, y * 64);
	else if (p == 63)
		mlx_put_image_to_window(g->mlx->m, g->mlx->w, c[3].i, x * 64, y * 64);
	else if (p == 64)
		mlx_put_image_to_window(g->mlx->m, g->mlx->w, c[4].i, x * 64, y * 64);
	else if (p == 65)
		mlx_put_image_to_window(g->mlx->m, g->mlx->w, c[5].i, x * 64, y * 64);
}
