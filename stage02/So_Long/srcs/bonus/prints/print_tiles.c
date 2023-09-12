/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:53:40 by argomez           #+#    #+#             */
/*   Updated: 2022/06/07 15:46:45 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	print_tiles(t_game *g, int y, int x, char c)
{
	t_img	*t;

	t = g->t;
	if (c == '2')
		mlx_put_image_to_window(g->mlx->m, g->mlx->w, t[0].i, x * 64, y * 64);
	else if (c == '3')
		mlx_put_image_to_window(g->mlx->m, g->mlx->w, t[1].i, x * 64, y * 64);
	else if (c == '4')
		mlx_put_image_to_window(g->mlx->m, g->mlx->w, t[2].i, x * 64, y * 64);
	else if (c == '5')
		mlx_put_image_to_window(g->mlx->m, g->mlx->w, t[3].i, x * 64, y * 64);
	else if (c == '6')
		mlx_put_image_to_window(g->mlx->m, g->mlx->w, t[4].i, x * 64, y * 64);
	else if (c == '7')
		mlx_put_image_to_window(g->mlx->m, g->mlx->w, t[5].i, x * 64, y * 64);
}
