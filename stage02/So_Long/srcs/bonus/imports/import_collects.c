/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_collects.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:04:18 by argomez           #+#    #+#             */
/*   Updated: 2022/06/02 15:07:24 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	init_collects(t_game *g)
{
	t_img	*c;
	int		i;

	c = g->c;
	c[0].p = "imgs/collectibles/1.xpm";
	c[1].p = "imgs/collectibles/2.xpm";
	c[2].p = "imgs/collectibles/3.xpm";
	c[3].p = "imgs/collectibles/4.xpm";
	c[4].p = "imgs/collectibles/5.xpm";
	c[5].p = "imgs/collectibles/6.xpm";
	i = -1;
	while (++i < 6)
	{	
		c[i].w = 64;
		c[i].h = 64;
		c[i].i = mlx_xpm_file_to_image(g->mlx->m, c[i].p, &c[i].w, &c[i].h);
	}
}

void	import_collects(t_game *g)
{
	g->c = malloc(sizeof(t_img) * 6);
	init_collects(g);
}
