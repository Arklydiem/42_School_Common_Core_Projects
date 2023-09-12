/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 11:16:06 by argomez           #+#    #+#             */
/*   Updated: 2023/02/10 14:46:16 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	move_player_up(t_data *datas)
{
	t_coordinate	*player;
	t_coordinate	*_player;

	player = &datas->player;
	_player = &datas->_player;
	if (datas->map[(int)player->y][(int)(player->x + _player->x * MS)] == '0')
		player->x += _player->x * MS;
	else if (datas->map[(int)player->y][(int)(player->x + _player->x * MS)] \
		== 'O')
		player->x += _player->x * MS;
	if (datas->map[(int)(player->y + _player->y * MS)][(int)player->x] == '0')
		player->y += _player->y * MS;
	else if (datas->map[(int)(player->y + _player->y * MS)][(int)player->x] \
		== 'O')
		player->y += _player->y * MS;
}

void	move_player_down(t_data *datas)
{
	t_coordinate	*player;
	t_coordinate	*_player;

	player = &datas->player;
	_player = &datas->_player;
	if (datas->map[(int)player->y][(int)(player->x - _player->x * MS)] == '0')
		player->x -= _player->x * MS;
	else if (datas->map[(int)player->y][(int)(player->x - _player->x * MS)] \
		== 'O')
		player->x -= _player->x * MS;
	if (datas->map[(int)(player->y - _player->y * MS)][(int)player->x] == '0')
		player->y -= _player->y * MS;
	else if (datas->map[(int)(player->y - _player->y * MS)][(int)player->x] \
		== 'O')
		player->y -= _player->y * MS;
}

void	move_player_left(t_data *datas)
{
	t_coordinate	*plr;
	t_coordinate	*pln;

	plr = &datas->player;
	pln = &datas->plane;
	if (datas->start == 'N' || datas->start == 'E')
	{
		if (datas->map[(int)plr->y][(int)(plr->x - pln->x * MS)] == '0')
			plr->x -= pln->x * MS;
		else if (datas->map[(int)plr->y][(int)(plr->x - pln->x * MS)] == 'O')
			plr->x -= pln->x * MS;
		if (datas->map[(int)(plr->y - pln->y * MS)][(int)plr->x] == '0')
			plr->y -= pln->y * MS;
		else if (datas->map[(int)(plr->y - pln->y * MS)][(int)plr->x] == 'O')
			plr->y -= pln->y * MS;
		return ;
	}
	if (datas->map[(int)plr->y][(int)(plr->x + pln->x * MS)] == '0')
		plr->x += pln->x * MS;
	else if (datas->map[(int)plr->y][(int)(plr->x + pln->x * MS)] == 'O')
		plr->x += pln->x * MS;
	if (datas->map[(int)(plr->y + pln->y * MS)][(int)plr->x] == '0')
		plr->y += pln->y * MS;
	else if (datas->map[(int)(plr->y + pln->y * MS)][(int)plr->x] == 'O')
		plr->y += pln->y * MS;
}

void	move_player_right(t_data *datas)
{
	t_coordinate	*plr;
	t_coordinate	*pln;

	plr = &datas->player;
	pln = &datas->plane;
	if (datas->start == 'S' || datas->start == 'W')
	{
		if (datas->map[(int)plr->y][(int)(plr->x - pln->x * MS)] == '0')
			plr->x -= pln->x * MS;
		else if (datas->map[(int)plr->y][(int)(plr->x - pln->x * MS)] == 'O')
			plr->x -= pln->x * MS;
		if (datas->map[(int)(plr->y - pln->y * MS)][(int)plr->x] == '0')
			plr->y -= pln->y * MS;
		else if (datas->map[(int)(plr->y - pln->y * MS)][(int)plr->x] == 'O')
			plr->y -= pln->y * MS;
		return ;
	}
	if (datas->map[(int)plr->y][(int)(plr->x + pln->x * MS)] == '0')
		plr->x += pln->x * MS;
	else if (datas->map[(int)plr->y][(int)(plr->x + pln->x * MS)] == 'O')
		plr->x += pln->x * MS;
	if (datas->map[(int)(plr->y + pln->y * MS)][(int)plr->x] == '0')
		plr->y += pln->y * MS;
	else if (datas->map[(int)(plr->y + pln->y * MS)][(int)plr->x] == 'O')
		plr->y += pln->y * MS;
}
