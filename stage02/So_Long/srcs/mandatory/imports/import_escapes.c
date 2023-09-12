/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_escapes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 21:16:10 by argomez           #+#    #+#             */
/*   Updated: 2022/06/02 15:09:18 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	init_escapes(t_game *g)
{
	t_img	*e;
	int		i;

	e = g->e;
	e[0].p = "imgs/escapes/1.xpm";
	e[1].p = "imgs/escapes/2.xpm";
	i = -1;
	while (++i < 2)
	{
		e[i].w = 64;
		e[i].h = 64;
		e[i].i = mlx_xpm_file_to_image(g->mlx->m, e[i].p, &e[i].w, &e[i].h);
	}
}

void	import_escapes(t_game *g)
{
	g->e = malloc(sizeof(t_img) * 2);
	init_escapes(g);
}
