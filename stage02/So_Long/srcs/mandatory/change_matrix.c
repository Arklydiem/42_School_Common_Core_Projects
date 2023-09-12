/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 16:02:30 by argomez           #+#    #+#             */
/*   Updated: 2022/06/07 17:46:11 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	choose_start(t_game *g, int y, int x)
{
	t_map		*m;
	static int	count;

	m = g->map;
	if (m->matrix[y][x] == 'P' && count++ != 0)
		m->matrix[y][x] = '0';
}

static void	choose_escape(t_game *g, int y, int x)
{
	t_map		*m;
	static int	count;

	m = g->map;
	if (m->matrix[y][x] == 'E' && count++ != 0)
		m->matrix[y][x] = '0';
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
		}
	}
}
