/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_count.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 11:08:04 by argomez           #+#    #+#             */
/*   Updated: 2022/06/01 16:51:55 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	print_count(t_game *g, int nb, int x, int y)
{
	t_img	*n;
	int		r;

	n = g->n;
	if (nb == 0)
		mlx_put_image_to_window(g->mlx->m, g->mlx->w, n[nb].i, x + 32, y);
	while (nb > 0)
	{
		r = nb % 10;
		mlx_put_image_to_window(g->mlx->m, g->mlx->w, n[r].i, x + 32, y);
		x -= 16;
		nb /= 10;
	}
}

void	display_count(t_game *g, int count)
{
	int	x;

	x = g->map->x;
	print_count(g, count, (x + 1) * 64, 24);
}
