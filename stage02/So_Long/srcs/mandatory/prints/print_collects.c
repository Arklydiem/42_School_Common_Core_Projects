/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_collects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 15:26:52 by argomez           #+#    #+#             */
/*   Updated: 2022/06/07 17:42:35 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	print_collects(t_game *g, int y, int x, char p)
{
	t_img	*c;

	c = g->c;
	(void)p;
	mlx_put_image_to_window(g->mlx->m, g->mlx->w, c[0].i, x * 64, y * 64);
}
