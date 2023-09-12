/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_file_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:46:20 by vnadal            #+#    #+#             */
/*   Updated: 2023/02/10 14:46:35 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	manage_texture(int fd, t_data *datas)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!check_empty_line(line))
			save_texture(line, fd, datas);
		else
			free(line);
		if (check_empty_texture(datas->textures) == 0)
			break ;
	}
	if (check_textures_rgb(datas->textures) == 0)
		ft_error(7, fd, datas);
}

static void	manage_map(int fd, t_data *datas)
{
	char	*line;

	line = skip_empty_lines(fd, datas);
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	datas->map = realloc_tab_str(datas->map, line);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		datas->map = realloc_tab_str(datas->map, line);
	}
	close(fd);
	check_map_validity(datas);
}

void	manage_file(char *str, t_data *datas)
{
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		ft_error(3, 0, datas);
	manage_texture(fd, datas);
	manage_map(fd, datas);
	if (datas->player.x == -1)
		ft_error(11, 0, datas);
}
