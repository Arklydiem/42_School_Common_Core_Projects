/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_player_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:24:40 by argomez           #+#    #+#             */
/*   Updated: 2023/02/10 14:46:23 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	rotate_player_left(t_data *datas)
{
	double	old_player_x;
	double	old_plane_x;

	old_player_x = datas->_player.x;
	old_plane_x = datas->plane.x;
	datas->_player.x = datas->_player.x * cos(-ROTATION_SPEED) \
		- datas->_player.y * sin(-ROTATION_SPEED);
	datas->_player.y = old_player_x * sin(-ROTATION_SPEED) \
		+ datas->_player.y * cos(-ROTATION_SPEED);
	datas->plane.x = datas->plane.x * cos(-ROTATION_SPEED) \
		- datas->plane.y * sin(-ROTATION_SPEED);
	datas->plane.y = old_plane_x * sin(-ROTATION_SPEED) \
		+ datas->plane.y * cos(-ROTATION_SPEED);
}

void	rotate_player_right(t_data *datas)
{
	double	old_player_x;
	double	old_plane_x;

	old_player_x = datas->_player.x;
	old_plane_x = datas->plane.x;
	datas->_player.x = datas->_player.x * cos(ROTATION_SPEED) \
		- datas->_player.y * sin(ROTATION_SPEED);
	datas->_player.y = old_player_x * sin(ROTATION_SPEED) \
		+ datas->_player.y * cos(ROTATION_SPEED);
	datas->plane.x = datas->plane.x * cos(ROTATION_SPEED) \
		- datas->plane.y * sin(ROTATION_SPEED);
	datas->plane.y = old_plane_x * sin(ROTATION_SPEED) \
		+ datas->plane.y * cos(ROTATION_SPEED);
}
