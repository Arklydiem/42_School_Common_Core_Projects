/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 12:53:40 by argomez           #+#    #+#             */
/*   Updated: 2022/06/22 16:56:11 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	print_tiles(t_game *g, int y, int x, char c)
{
	t_img	*t;

	t = g->t;
	if (c == 'E')
		mlx_put_image_to_window(g->mlx->m, g->mlx->w, t[3].i, x * 64, y * 64);
	else
		mlx_put_image_to_window(g->mlx->m, g->mlx->w, t[2].i, x * 64, y * 64);
}
