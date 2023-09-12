/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 19:44:22 by argomez           #+#    #+#             */
/*   Updated: 2022/06/07 14:18:13 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	game_init(t_game *game)
{
	game->map = NULL;
	game->w = NULL;
	game->t = NULL;
	game->c = NULL;
	game->e = NULL;
	game->up = NULL;
	game->down = NULL;
	game->left = NULL;
	game->right = NULL;
}
