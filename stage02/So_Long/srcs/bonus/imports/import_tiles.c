/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_tiles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:04:18 by argomez           #+#    #+#             */
/*   Updated: 2022/06/02 15:18:41 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	init_tiles(t_game *g)
{
	t_img	*t;
	int		i;

	t = g->t;
	t[0].p = "imgs/tiles/1.xpm";
	t[1].p = "imgs/tiles/2.xpm";
	t[2].p = "imgs/tiles/3.xpm";
	t[3].p = "imgs/tiles/4.xpm";
	t[4].p = "imgs/tiles/5.xpm";
	t[5].p = "imgs/tiles/6.xpm";
	i = -1;
	while (++i < 6)
	{	
		t[i].w = 64;
		t[i].h = 64;
		t[i].i = mlx_xpm_file_to_image(g->mlx->m, t[i].p, &t[i].w, &t[i].h);
	}
}

void	import_tiles(t_game *g)
{
	g->t = malloc(sizeof(t_img) * 6);
	init_tiles(g);
}
