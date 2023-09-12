/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_players.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:50:16 by argomez           #+#    #+#             */
/*   Updated: 2022/06/07 15:47:00 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	print_player_up(t_game *g, t_entity *e, char cell)
{
	if (cell == 'E')
		print_player_up(g, e, '5');
	else
		put_image_entity(g, g->up, e, cell % 10);
}

void	print_player_down(t_game *g, t_entity *e, char cell)
{
	if (cell == 'E')
		print_player_down(g, e, '5');
	else
		put_image_entity(g, g->down, e, cell % 10);
}

void	print_player_left(t_game *g, t_entity *e, char cell)
{
	if (cell == 'E')
		print_player_left(g, e, '5');
	else
		put_image_entity(g, g->left, e, cell % 10);
}

void	print_player_right(t_game *g, t_entity *e, char cell)
{
	if (cell == 'E')
		print_player_right(g, e, '5');
	else
		put_image_entity(g, g->right, e, cell % 10);
}

void	print_player(t_game *g, t_entity *e)
{
	char	cell;
	int		key;
	int		x;
	int		y;

	x = e->x;
	y = e->y;
	cell = g->map->matrix[y][x];
	key = g->map->key;
	if (key == XK_Up || key == XK_w)
		print_player_up(g, e, cell);
	else if (key == XK_Down || key == XK_s)
		print_player_down(g, e, cell);
	else if (key == XK_Left || key == XK_a)
		print_player_left(g, e, cell);
	else if (key == XK_Right || key == XK_d)
		print_player_right(g, e, cell);
}
