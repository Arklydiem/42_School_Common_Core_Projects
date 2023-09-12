/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:21:09 by argomez           #+#    #+#             */
/*   Updated: 2022/06/07 17:23:15 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static int	check_key(int key)
{
	if (key == XK_Up)
		return (1);
	else if (key == XK_Down)
		return (1);
	else if (key == XK_Left)
		return (1);
	else if (key == XK_Right)
		return (1);
	else if (key == XK_w)
		return (1);
	else if (key == XK_s)
		return (1);
	else if (key == XK_a)
		return (1);
	else if (key == XK_d)
		return (1);
	return (0);
}

static int	deal_key(int key, t_game *game)
{
	if (key == XK_Escape)
		clear_game(game);
	if (check_key(key) == 1)
	{
		game->map->key = key;
		move_entities(key, game);
	}
	return (0);
}

static int	cross_leaving(t_game *game)
{
	clear_game(game);
	return (0);
}

static int	animations(t_game *g)
{
	static int	rate;

	if (rate == 20000)
	{
		g->map->b *= -1;
		print_player(g, g->map->player);
		print_sentinels(g);
		if (g->map->count_collects == g->map->nb_collects)
			print_escape(g, g->map->ey, g->map->ex, g->map->b);
		rate = 0;
	}
	rate++;
	return (0);
}

void	open_window(t_game *game)
{
	t_mlx	*disp;
	int		width;
	int		height;

	game->mlx = malloc(sizeof(t_mlx));
	disp = game->mlx;
	width = (game->map->x + 2) * 64;
	height = (game->map->y + 2) * 64;
	disp->m = mlx_init();
	disp->w = mlx_new_window(disp->m, width, height, "So_Long");
	import_images(game);
	print_images(game);
	mlx_loop_hook(disp->m, animations, game);
	mlx_key_hook(disp->w, deal_key, game);
	mlx_hook(disp->w, DestroyNotify, 0, cross_leaving, game);
	mlx_loop(disp->m);
}
