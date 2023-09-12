/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_entities.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 21:06:27 by argomez           #+#    #+#             */
/*   Updated: 2022/06/07 15:45:20 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	move_up(t_game *g, t_entity *player, int key)
{
	char	cell;

	if (able_to_move(g, player->y - 1, player->x) == 0)
		return ;
	reset_case(g, g->map->sentinel);
	reset_case(g, g->map->player);
	push_entity(g, g->map->sentinel, key);
	push_entity(g, g->map->player, key);
	cell = g->map->matrix[player->y][player->x];
	if (60 <= cell && cell <= 65)
		g->map->count_collects++;
	if (player_on_sentinel(g->map->player, g->map->sentinel) == 1)
		clear_game(g);
	print_player(g, player);
	print_sentinels(g);
	display_count(g, ++g->map->count_moves);
}

static void	move_down(t_game *g, t_entity *player, int key)
{
	char	cell;

	if (able_to_move(g, player->y + 1, player->x) == 0)
		return ;
	reset_case(g, g->map->sentinel);
	reset_case(g, g->map->player);
	push_entity(g, g->map->sentinel, key);
	push_entity(g, g->map->player, key);
	cell = g->map->matrix[player->y][player->x];
	if (60 <= cell && cell <= 65)
		g->map->count_collects++;
	if (player_on_sentinel(g->map->player, g->map->sentinel) == 1)
		clear_game(g);
	print_player(g, player);
	print_sentinels(g);
	display_count(g, ++g->map->count_moves);
}

static void	move_left(t_game *g, t_entity *player, int key)
{
	char	cell;

	if (able_to_move(g, player->y, player->x - 1) == 0)
		return ;
	reset_case(g, g->map->sentinel);
	reset_case(g, g->map->player);
	push_entity(g, g->map->sentinel, key);
	push_entity(g, g->map->player, key);
	cell = g->map->matrix[player->y][player->x];
	if (60 <= cell && cell <= 65)
		g->map->count_collects++;
	if (player_on_sentinel(g->map->player, g->map->sentinel) == 1)
		clear_game(g);
	print_player(g, player);
	print_sentinels(g);
	display_count(g, ++g->map->count_moves);
}

static void	move_right(t_game *g, t_entity *player, int key)
{
	char	cell;

	if (able_to_move(g, player->y, player->x + 1) == 0)
		return ;
	reset_case(g, g->map->sentinel);
	reset_case(g, g->map->player);
	push_entity(g, g->map->sentinel, key);
	push_entity(g, g->map->player, key);
	cell = g->map->matrix[player->y][player->x];
	if (60 <= cell && cell <= 65)
		g->map->count_collects++;
	if (player_on_sentinel(g->map->player, g->map->sentinel) == 1)
		clear_game(g);
	print_player(g, player);
	print_sentinels(g);
	display_count(g, ++g->map->count_moves);
}

void	move_entities(int key, t_game *g)
{
	t_entity	*player;

	player = g->map->player;
	if (key == XK_Up || key == XK_w)
		move_up(g, player, key);
	else if (key == XK_Down || key == XK_s)
		move_down(g, player, key);
	else if (key == XK_Left || key == XK_a)
		move_left(g, player, key);
	else if (key == XK_Right || key == XK_d)
		move_right(g, player, key);
	if (player_on_escape(g, g->map->player) == 1)
		clear_game(g);
}
