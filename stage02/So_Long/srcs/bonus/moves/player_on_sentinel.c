/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_on_sentinel.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 22:28:27 by argomez           #+#    #+#             */
/*   Updated: 2022/06/02 22:30:00 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	player_on_sentinel(t_entity *p, t_entity *s)
{
	if (p->y == s->y && p->x == s->x)
		return (1);
	return (0);
}
