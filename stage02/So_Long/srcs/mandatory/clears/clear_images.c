/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_images.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 11:50:19 by argomez           #+#    #+#             */
/*   Updated: 2022/06/02 17:24:08 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	clear_chars(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 12)
		mlx_destroy_image(game->mlx->m, game->left[i].i);
	i = -1;
	while (++i < 12)
		mlx_destroy_image(game->mlx->m, game->right[i].i);
	i = -1;
	while (++i < 12)
		mlx_destroy_image(game->mlx->m, game->up[i].i);
	i = -1;
	while (++i < 12)
		mlx_destroy_image(game->mlx->m, game->down[i].i);
}

void	clear_images(t_game *game)
{
	int	i;

	i = -1;
	while (++i < 12)
		mlx_destroy_image(game->mlx->m, game->w[i].i);
	i = -1;
	while (++i < 6)
		mlx_destroy_image(game->mlx->m, game->t[i].i);
	i = -1;
	while (++i < 6)
		mlx_destroy_image(game->mlx->m, game->c[i].i);
	i = -1;
	while (++i < 2)
		mlx_destroy_image(game->mlx->m, game->e[i].i);
	i = -1;
	while (++i < 10)
		mlx_destroy_image(game->mlx->m, game->n[i].i);
	i = -1;
	while (++i < 12)
		mlx_destroy_image(game->mlx->m, game->s[i].i);
	clear_chars(game);
}
