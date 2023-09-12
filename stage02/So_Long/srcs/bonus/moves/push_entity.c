/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_entity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:42:27 by argomez           #+#    #+#             */
/*   Updated: 2022/06/22 16:14:39 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	push_sentinel(t_game *g, t_entity *e, int direction)
{
	if (direction > 4)
		direction = 0;
	if (direction == 0)
	{
		direction = (int)(rand() / (double)RAND_MAX * 5);
		direction++;
	}
	if (direction == 1 && able_to_move(g, e->y - 1, e->x) == 1)
		e->y--;
	else if (direction == 2 && able_to_move(g, e->y + 1, e->x) == 1)
		e->y++;
	else if (direction == 3 && able_to_move(g, e->y, e->x - 1) == 1)
		e->x--;
	else if (direction == 4 && able_to_move(g, e->y, e->x + 1) == 1)
		e->x++;
}

void	push_entity(t_game *g, t_entity *e, int key)
{
	if (e->state == 1)
	{
		if (key == XK_Up || key == XK_w)
			e->y--;
		else if (key == XK_Down || key == XK_s)
			e->y++;
		else if (key == XK_Left || key == XK_a)
			e->x--;
		else if (key == XK_Right || key == XK_d)
			e->x++;
	}
	else if (e->state == -1)
		push_sentinel(g, e, 0);
}
