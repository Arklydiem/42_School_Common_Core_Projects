/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:15:41 by argomez           #+#    #+#             */
/*   Updated: 2022/06/07 18:05:42 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	check_symbol(t_game *g, int y, int x)
{
	t_map	*m;

	m = g->map;
	if (m->matrix[y][x] == '1')
		print_walls(g, y + 1, x + 1);
	else if (m->matrix[y][x] == '0')
		print_tiles(g, y + 1, x + 1, 'p');
	else if (m->matrix[y][x] == 'C')
		print_collects(g, y + 1, x + 1, 'p');
	else if (m->matrix[y][x] == 'P' || m->matrix[y][x] == 'E')
		print_start_end(g, y + 1, x + 1, m->matrix[y][x]);
}

void	print_images(t_game *game)
{
	int		y;
	int		x;

	srand(time(NULL));
	y = -1;
	game->map->player = malloc(sizeof(t_entity));
	game->map->player->state = 1;
	while (++y < game->map->y)
	{
		x = -1;
		while (++x < game->map->x)
			check_symbol(game, y, x);
	}
}
