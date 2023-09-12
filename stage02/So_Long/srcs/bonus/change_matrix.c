/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:02:30 by argomez           #+#    #+#             */
/*   Updated: 2022/06/07 17:47:08 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	choose_start(t_game *g, int y, int x)
{
	t_map		*m;
	static int	count_s;
	static int	r_s;

	m = g->map;
	if (!r_s)
		r_s = (int)(rand() / (double)RAND_MAX * (m->nb_starts - 1));
	if (m->matrix[y][x] == 'P' && r_s != count_s++)
		m->matrix[y][x] = '0';
}

static void	choose_escape(t_game *g, int y, int x)
{
	t_map		*m;
	static int	count_e;
	static int	r_e;

	m = g->map;
	if (!r_e)
		r_e = (int)(rand() / (double)RAND_MAX * (m->nb_escapes - 1));
	if (m->matrix[y][x] == 'E' && r_e != count_e++)
		m->matrix[y][x] = '0';
}

static void	choose_maps(t_game *g, int y, int x)
{
	t_map		*m;

	m = g->map;
	if (m->matrix[y][x] == '0')
		m->matrix[y][x] += (int)(rand() / (double)RAND_MAX * (5)) + 2;
	else if (m->matrix[y][x] == 'C')
		m->matrix[y][x] += (int)(rand() / (double)RAND_MAX * (5)) - 7;
}

void	change_matrix(t_game *g)
{
	t_map	*m;
	int		y;
	int		x;

	y = -1;
	srand(time(NULL));
	m = g->map;
	while (++y < m->y)
	{
		x = -1;
		while (++x < m->x)
		{
			choose_start(g, y, x);
			choose_escape(g, y, x);
			choose_maps(g, y, x);
		}
	}
}
