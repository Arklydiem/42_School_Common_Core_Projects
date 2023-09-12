/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 14:19:13 by argomez           #+#    #+#             */
/*   Updated: 2022/06/07 14:19:16 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	map_init(t_map *map)
{
	map->name = NULL;
	map->x = 0;
	map->y = 0;
	map->matrix = NULL;
	map->nb_starts = 0;
	map->nb_escapes = 0;
	map->nb_collects = 0;
	map->player = NULL;
	map->count_collects = 0;
	map->count_moves = 0;
	map->key = 119;
}
