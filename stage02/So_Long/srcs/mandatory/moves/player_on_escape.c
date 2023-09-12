/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_on_escape.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 11:42:41 by argomez           #+#    #+#             */
/*   Updated: 2022/06/07 15:42:58 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	player_on_escape(t_game *g, t_entity *p)
{
	if (g->map->count_collects == g->map->nb_collects)
	{
		if (g->map->ex == p->x && g->map->ey == p->y)
			return (1);
		return (0);
	}
	return (0);
}
