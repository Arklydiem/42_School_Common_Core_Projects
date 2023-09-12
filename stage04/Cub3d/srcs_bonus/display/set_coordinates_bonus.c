/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_coordinates_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:56:16 by argomez           #+#    #+#             */
/*   Updated: 2023/02/10 14:46:26 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	set_coordinates(t_data *datas)
{
	t_coordinate	*player;
	t_coordinate	*plane;

	set_player_direction(datas);
	player = &datas->player;
	player->x += 0.5;
	player->y += 0.5;
	plane = &datas->plane;
	if ((datas->_player.x == 0 && datas->_player.y == -1)
		|| (datas->_player.x == 0 && datas->_player.y == 1))
		plane->x = 0.66;
	else
		plane->x = 0;
	if ((datas->_player.x == 1 && datas->_player.y == 0)
		|| (datas->_player.x == -1 && datas->_player.y == 0))
		plane->y = 0.66;
	else
		plane->y = 0;
}
