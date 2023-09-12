/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:04:18 by argomez           #+#    #+#             */
/*   Updated: 2022/06/02 15:13:01 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	init_walls(t_game *g)
{
	t_img	*w;
	int		i;

	w = g->w;
	w[0].p = "imgs/limits/walls/1.xpm";
	w[1].p = "imgs/limits/walls/2.xpm";
	w[2].p = "imgs/limits/walls/3.xpm";
	w[3].p = "imgs/limits/walls/4.xpm";
	w[4].p = "imgs/limits/walls/5.xpm";
	w[5].p = "imgs/limits/walls/6.xpm";
	w[6].p = "imgs/limits/walls/7.xpm";
	w[7].p = "imgs/limits/walls/8.xpm";
	w[8].p = "imgs/limits/trees/1.xpm";
	w[9].p = "imgs/limits/trees/2.xpm";
	w[10].p = "imgs/limits/trees/3.xpm";
	w[11].p = "imgs/limits/trees/4.xpm";
	i = -1;
	while (++i < 12)
	{	
		w[i].w = 64;
		w[i].h = 64;
		w[i].i = mlx_xpm_file_to_image(g->mlx->m, w[i].p, &w[i].w, &w[i].h);
	}
}

void	import_walls(t_game *g)
{
	g->w = malloc(sizeof(t_img) * 12);
	init_walls(g);
}
