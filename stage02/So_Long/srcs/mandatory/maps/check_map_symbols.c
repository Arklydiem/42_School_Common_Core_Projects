/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_symbols.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 10:25:18 by argomez           #+#    #+#             */
/*   Updated: 2022/06/23 12:52:37 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	check_first_last_lines(char *line, t_game *game)
{
	int	x;

	x = -1;
	while (line[++x])
	{
		if (line[x] != '1' && x < game->map->x)
		{
			if (line[x] != '1')
				ft_error(16, game);
			if (x != game->map->x)
				break ;
		}
	}
	if (x != game->map->x)
		ft_error(17, game);
}

static void	check_symbol(char c, t_game *game)
{
	if (!(c == '1' || c == '0' || c == 'E' || c == 'P' || c == 'C'))
		ft_error(18, game);
	else if (c == 'P')
		game->map->nb_starts++;
	else if (c == 'E')
		game->map->nb_escapes++;
	else if (c == 'C')
		game->map->nb_collects++;
}

static void	check_other_lines(char *line, t_game *game)
{
	int	x;

	x = -1;
	while (line[++x])
		check_symbol(line[x], game);
	if (x != game->map->x)
		ft_error(17, game);
	if (line[0] != '1' || line[x - 1] != '1')
		ft_error(16, game);
}

void	check_map_symbols(char *line, int y, t_game *game)
{
	if (y == 0 || y == game->map->y - 1)
		check_first_last_lines(line, game);
	else
		check_other_lines(line, game);
}
