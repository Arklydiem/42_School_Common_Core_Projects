/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:51:44 by argomez           #+#    #+#             */
/*   Updated: 2022/06/07 18:14:26 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	clear_map(t_map *map)
{
	int	i;

	free(map->name);
	if (map->matrix)
	{
		i = -1;
		while (map->matrix[++i] != NULL)
			free(map->matrix[i]);
		free(map->matrix);
	}
	if (map->player)
		free(map->player);
	free(map);
}

static void	clear_mlx(t_game *g)
{
	mlx_clear_window(g->mlx->m, g->mlx->w);
	clear_images(g);
	mlx_destroy_window(g->mlx->m, g->mlx->w);
	mlx_destroy_display(g->mlx->m);
	free(g->mlx->m);
	free(g->mlx);
}

void	clear_game(t_game *game)
{
	if (game->map)
		clear_map(game->map);
	if (game->mlx)
		clear_mlx(game);
	free(game->w);
	free(game->t);
	free(game->c);
	free(game->e);
	free(game->left);
	free(game->up);
	free(game->right);
	free(game->down);
	free(game->n);
	free(game->s);
	free(game);
	exit(0);
}
