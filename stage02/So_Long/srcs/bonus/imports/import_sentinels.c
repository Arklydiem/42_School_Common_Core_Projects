/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_sentinels.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:04:18 by argomez           #+#    #+#             */
/*   Updated: 2022/06/02 15:23:30 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	init_sentinels(t_game *g)
{
	t_img	*s;
	int		i;

	s = g->s;
	s[0].p = "imgs/sentinels/1.xpm";
	s[1].p = "imgs/sentinels/2.xpm";
	s[2].p = "imgs/sentinels/3.xpm";
	s[3].p = "imgs/sentinels/4.xpm";
	s[4].p = "imgs/sentinels/5.xpm";
	s[5].p = "imgs/sentinels/6.xpm";
	s[6].p = "imgs/sentinels/11.xpm";
	s[7].p = "imgs/sentinels/12.xpm";
	s[8].p = "imgs/sentinels/13.xpm";
	s[9].p = "imgs/sentinels/14.xpm";
	s[10].p = "imgs/sentinels/15.xpm";
	s[11].p = "imgs/sentinels/16.xpm";
	i = -1;
	while (++i < 12)
	{	
		s[i].w = 64;
		s[i].h = 64;
		s[i].i = mlx_xpm_file_to_image(g->mlx->m, s[i].p, &s[i].w, &s[i].h);
	}
}

void	import_sentinels(t_game *g)
{
	g->s = malloc(sizeof(t_img) * 12);
	init_sentinels(g);
}
