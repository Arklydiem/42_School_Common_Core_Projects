/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sentinels.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:50:16 by argomez           #+#    #+#             */
/*   Updated: 2022/06/07 15:30:08 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	print_sentinel(t_game *g, t_entity *e, char cell)
{
	if (cell == 'E')
		put_image_entity(g, g->s, e, '5' % 10);
	else
		put_image_entity(g, g->s, e, cell % 10);
}

void	print_sentinels(t_game *g)
{
	int		x;
	int		y;

	x = g->map->sentinel->x;
	y = g->map->sentinel->y;
	print_sentinel(g, g->map->sentinel, g->map->matrix[y][x]);
}
