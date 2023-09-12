/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_chars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:38:11 by argomez           #+#    #+#             */
/*   Updated: 2022/06/02 15:01:27 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	init_left(t_game *g)
{
	t_img	*l;
	int		i;

	l = g->left;
	l[0].p = "imgs/char/left/1.xpm";
	l[1].p = "imgs/char/left/2.xpm";
	l[2].p = "imgs/char/left/3.xpm";
	l[3].p = "imgs/char/left/4.xpm";
	l[4].p = "imgs/char/left/5.xpm";
	l[5].p = "imgs/char/left/6.xpm";
	l[6].p = "imgs/char/left/11.xpm";
	l[7].p = "imgs/char/left/12.xpm";
	l[8].p = "imgs/char/left/13.xpm";
	l[9].p = "imgs/char/left/14.xpm";
	l[10].p = "imgs/char/left/15.xpm";
	l[11].p = "imgs/char/left/16.xpm";
	i = -1;
	while (++i < 12)
	{
		l[i].w = 64;
		l[i].h = 64;
		l[i].i = mlx_xpm_file_to_image(g->mlx->m, l[i].p, &l[i].w, &l[i].h);
	}
}

static void	init_up(t_game *g)
{
	t_img	*u;
	int		i;

	u = g->up;
	u[0].p = "imgs/char/up/1.xpm";
	u[1].p = "imgs/char/up/2.xpm";
	u[2].p = "imgs/char/up/3.xpm";
	u[3].p = "imgs/char/up/4.xpm";
	u[4].p = "imgs/char/up/5.xpm";
	u[5].p = "imgs/char/up/6.xpm";
	u[6].p = "imgs/char/up/11.xpm";
	u[7].p = "imgs/char/up/12.xpm";
	u[8].p = "imgs/char/up/13.xpm";
	u[9].p = "imgs/char/up/14.xpm";
	u[10].p = "imgs/char/up/15.xpm";
	u[11].p = "imgs/char/up/16.xpm";
	i = -1;
	while (++i < 12)
	{
		u[i].w = 64;
		u[i].h = 64;
		u[i].i = mlx_xpm_file_to_image(g->mlx->m, u[i].p, &u[i].w, &u[i].h);
	}
}

static void	init_right(t_game *g)
{
	t_img	*r;
	int		i;

	r = g->right;
	r[0].p = "imgs/char/right/1.xpm";
	r[1].p = "imgs/char/right/2.xpm";
	r[2].p = "imgs/char/right/3.xpm";
	r[3].p = "imgs/char/right/4.xpm";
	r[4].p = "imgs/char/right/5.xpm";
	r[5].p = "imgs/char/right/6.xpm";
	r[6].p = "imgs/char/right/11.xpm";
	r[7].p = "imgs/char/right/12.xpm";
	r[8].p = "imgs/char/right/13.xpm";
	r[9].p = "imgs/char/right/14.xpm";
	r[10].p = "imgs/char/right/15.xpm";
	r[11].p = "imgs/char/right/16.xpm";
	i = -1;
	while (++i < 12)
	{
		r[i].w = 64;
		r[i].h = 64;
		r[i].i = mlx_xpm_file_to_image(g->mlx->m, r[i].p, &r[i].w, &r[i].h);
	}
}

static void	init_down(t_game *g)
{
	t_img	*d;
	int		i;

	d = g->down;
	d[0].p = "imgs/char/down/1.xpm";
	d[1].p = "imgs/char/down/2.xpm";
	d[2].p = "imgs/char/down/3.xpm";
	d[3].p = "imgs/char/down/4.xpm";
	d[4].p = "imgs/char/down/5.xpm";
	d[5].p = "imgs/char/down/6.xpm";
	d[6].p = "imgs/char/down/11.xpm";
	d[7].p = "imgs/char/down/12.xpm";
	d[8].p = "imgs/char/down/13.xpm";
	d[9].p = "imgs/char/down/14.xpm";
	d[10].p = "imgs/char/down/15.xpm";
	d[11].p = "imgs/char/down/16.xpm";
	i = -1;
	while (++i < 12)
	{
		d[i].w = 64;
		d[i].h = 64;
		d[i].i = mlx_xpm_file_to_image(g->mlx->m, d[i].p, &d[i].w, &d[i].h);
	}
}

void	import_chars(t_game *g)
{
	g->up = malloc(sizeof(t_img) * 12);
	g->down = malloc(sizeof(t_img) * 12);
	g->left = malloc(sizeof(t_img) * 12);
	g->right = malloc(sizeof(t_img) * 12);
	init_left(g);
	init_up(g);
	init_right(g);
	init_down(g);
}
