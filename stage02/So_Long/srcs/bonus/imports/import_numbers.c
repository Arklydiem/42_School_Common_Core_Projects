/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_numbers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:50:40 by argomez           #+#    #+#             */
/*   Updated: 2022/06/02 18:32:30 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	init_numbers(t_game *g)
{
	t_img	*n;
	int		i;

	n = g->n;
	n[0].p = "imgs/numbers/0.xpm";
	n[1].p = "imgs/numbers/1.xpm";
	n[2].p = "imgs/numbers/2.xpm";
	n[3].p = "imgs/numbers/3.xpm";
	n[4].p = "imgs/numbers/4.xpm";
	n[5].p = "imgs/numbers/5.xpm";
	n[6].p = "imgs/numbers/6.xpm";
	n[7].p = "imgs/numbers/7.xpm";
	n[8].p = "imgs/numbers/8.xpm";
	n[9].p = "imgs/numbers/9.xpm";
	i = -1;
	while (++i < 10)
	{
		n[i].w = 64;
		n[i].h = 64;
		n[i].i = mlx_xpm_file_to_image(g->mlx->m, n[i].p, &n[i].w, &n[i].h);
	}
}

void	import_numbers(t_game *g)
{
	g->n = malloc(sizeof(t_img) * 10);
	init_numbers(g);
}
