/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_entity.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:42:27 by argomez           #+#    #+#             */
/*   Updated: 2022/06/07 17:59:45 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

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
	(void)g;
}
