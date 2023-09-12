/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_inspector.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 11:08:43 by argomez           #+#    #+#             */
/*   Updated: 2022/06/23 12:08:34 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	ft_count_map_y(t_game *game)
{
	char	buff[1];
	int		fd;
	int		readed;

	fd = open(game->map->name, O_RDONLY);
	if (fd == -1)
		ft_error(11, game);
	readed = 1;
	while (readed != 0)
	{
		readed = read(fd, buff, 1);
		if (readed == 0 && game->map->y == 0)
			ft_error(12, game);
		if (buff[0] == '\n')
		{
			buff[0] = 0;
			game->map->y++;
		}
	}
	if (readed == 0 && (buff[0] == '1' || buff[0] == '0'))
		game->map->y++;
	if (close(fd) == -1)
		ft_error(13, game);
}

static void	ft_count_map_x(t_game *game)
{
	char	*line;
	int		fd;
	int		i;
	int		count;

	fd = open(game->map->name, O_RDONLY);
	if (fd == -1)
		ft_error(11, game);
	count = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		i = -1;
		game->map->matrix[count] = ft_calloc(ft_strlen(line), sizeof(char) + 1);
		while (line[++i] && line[i] != '\n')
			game->map->matrix[count][i] = line[i];
		if (game->map->x == 0)
			game->map->x = i;
		free(line);
		count++;
	}
	if (close(fd) == -1)
		ft_error(13, game);
}

static void	ft_map_parsing(t_game *game)
{
	int	y;

	y = -1;
	while (game->map->matrix[++y])
		check_map_symbols(game->map->matrix[y], y, game);
	if (game->map->nb_starts == 0
		|| game->map->nb_escapes == 0
		|| game->map->nb_collects == 0)
		ft_error(19, game);
}

static void	ft_define_map(char *file, t_game *game)
{
	game->map->name = ft_strdup(file);
	ft_count_map_y(game);
	if (game->map->y < 3)
		ft_error(14, game);
	game->map->matrix = ft_calloc(game->map->y + 2, sizeof(char *));
	ft_count_map_x(game);
	if (game->map->x < 3)
		ft_error(15, game);
	ft_map_parsing(game);
}

void	map_inspector(char **files, t_game *game)
{
	int		i;

	i = 0;
	while (files[i])
		ft_error(ft_extension(files[i++], ".ber"), game);
	game->map = malloc(sizeof(t_map));
	map_init(game->map);
	ft_define_map(files[0], game);
}
