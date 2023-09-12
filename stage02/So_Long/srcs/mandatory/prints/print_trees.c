/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_trees.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:06:20 by argomez           #+#    #+#             */
/*   Updated: 2022/06/07 17:45:07 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	print_trees(t_game *g, int y, int x)
{
	t_img	*w;

	w = g->w;
	mlx_put_image_to_window(g->mlx->m, g->mlx->w, w[8].i, x * 64, y * 64);
}
