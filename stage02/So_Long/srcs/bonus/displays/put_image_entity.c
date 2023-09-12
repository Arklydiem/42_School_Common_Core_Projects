/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image_entity.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 22:00:39 by argomez           #+#    #+#             */
/*   Updated: 2022/06/02 22:04:19 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	put_image_entity(t_game *g, t_img *i, t_entity *e, int j)
{
	t_mlx	*m;
	int		x;
	int		y;

	m = g->mlx;
	if (g->map->b == -1)
		i += 6;
	x = e->x + 1;
	y = e->y + 1;
	mlx_put_image_to_window(m->m, m->w, i[j].i, x * 64, y * 64);
}
