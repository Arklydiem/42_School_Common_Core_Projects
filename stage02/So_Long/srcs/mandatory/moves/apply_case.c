/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_case.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:37:00 by argomez           #+#    #+#             */
/*   Updated: 2022/06/07 14:51:56 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	apply_player(t_game *g, t_entity *e, int key)
{
	char	cell;

	cell = g->map->matrix[e->y][e->x];
	if (key == XK_Up || key == XK_w)
		print_player_up(g, e, cell);
	else if (key == XK_Down || key == XK_s)
		print_player_down(g, e, cell);
	else if (key == XK_Left || key == XK_a)
		print_player_left(g, e, cell);
	else if (key == XK_Right || key == XK_d)
		print_player_right(g, e, cell);
	if (60 <= cell && cell <= 65)
		g->map->count_collects++;
}

void	apply_case(t_game *g, t_entity *e, int key)
{
	if (e->state == -1)
		print_sentinels(g);
	else if (e->state == 1)
		apply_player(g, e, key);
}
