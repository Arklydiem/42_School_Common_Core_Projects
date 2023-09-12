/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:22:42 by argomez           #+#    #+#             */
/*   Updated: 2022/06/03 17:19:46 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	reset_case_player(t_game *g, t_entity *e, char cell)
{
	if (cell == 'P')
		g->map->matrix[e->y][e->x] = '2';
	else if (60 <= cell && cell <= 65)
		g->map->matrix[e->y][e->x] = cell - 10;
	cell = g->map->matrix[e->y][e->x];
	if (cell == 'E')
		cell -= 16;
	if ('2' <= cell && cell <= '7')
		print_tiles(g, e->y + 1, e->x + 1, cell);
}

static void	reset_case_sentinel(t_game *g, t_entity *e, char cell)
{
	if (cell == 'S')
		g->map->matrix[e->y][e->x] = '2';
	cell = g->map->matrix[e->y][e->x];
	if (cell == 'E')
		cell -= 16;
	if ('2' <= cell && cell <= '7')
		print_tiles(g, e->y + 1, e->x + 1, cell);
	if (60 <= cell && cell <= 65)
		print_collects(g, e->y + 1, e->x + 1, cell);
}

void	reset_case(t_game *g, t_entity *e)
{
	char	cell;

	cell = g->map->matrix[e->y][e->x];
	if (e->state == -1)
		reset_case_sentinel(g, e, cell);
	else if (e->state == 1)
		reset_case_player(g, e, cell);
}
