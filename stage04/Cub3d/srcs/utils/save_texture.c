/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:31:21 by vnadal            #+#    #+#             */
/*   Updated: 2023/02/10 12:42:27 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	**cut_texture_rgb(char *str)
{
	char	**rgb;
	int		i;

	i = 1;
	while (str && str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (NULL);
	rgb = ft_split(str + i, ',');
	if (!ft_isdigit(str[i]) || check_multiple_char(str, ',') > 1)
	{
		free(rgb[0]);
		rgb[0] = ft_strdup("INVALID");
	}
	i = 0;
	while (rgb[i])
	{
		if (rgb[i][ft_strlen(rgb[i]) - 1] == '\n')
			rgb[i][ft_strlen(rgb[i]) - 1] = '\0';
		i++;
	}
	return (rgb);
}

static char	*cut_texture_path(char *str)
{
	char	*path;
	int		i;

	i = 2;
	while (str && str[i] == ' ')
		i++;
	if (str[i] == '\0')
		return (NULL);
	path = ft_strdup(str + i);
	if (path[ft_strlen(path) - 1] == '\n')
		path[ft_strlen(path) - 1] = '\0';
	return (path);
}

static int	already_in(char *str, t_data *datas)
{
	if (ft_strncmp(str, "NO ", 3) == 0 && datas->textures.north)
		return (TRUE);
	else if (ft_strncmp(str, "SO ", 3) == 0 && datas->textures.south)
		return (TRUE);
	else if (ft_strncmp(str, "WE ", 3) == 0 && datas->textures.west)
		return (TRUE);
	else if (ft_strncmp(str, "EA ", 3) == 0 && datas->textures.east)
		return (TRUE);
	else if (ft_strncmp(str, "F ", 2) == 0 && datas->textures.floor)
		return (TRUE);
	else if (ft_strncmp(str, "C ", 2) == 0 && datas->textures.ceiling)
		return (TRUE);
	return (FALSE);
}

static void	check_texture_info(int i, char *str, int fd, t_data *datas)
{
	if (already_in(str, datas) == TRUE)
	{
		free(str - i);
		ft_error(14, fd, datas);
	}
	if (ft_strncmp(str, "NO ", 3) == 0)
		datas->textures.north = cut_texture_path(str);
	else if (ft_strncmp(str, "SO ", 3) == 0)
		datas->textures.south = cut_texture_path(str);
	else if (ft_strncmp(str, "WE ", 3) == 0)
		datas->textures.west = cut_texture_path(str);
	else if (ft_strncmp(str, "EA ", 3) == 0)
		datas->textures.east = cut_texture_path(str);
	else if (ft_strncmp(str, "F ", 2) == 0
		&& check_commas_in_rgb(str) == TRUE)
		datas->textures.floor = cut_texture_rgb(str);
	else if (ft_strncmp(str, "C ", 2) == 0
		&& check_commas_in_rgb(str) == TRUE)
		datas->textures.ceiling = cut_texture_rgb(str);
	else
	{
		free(str - i);
		ft_error(4, fd, datas);
	}
}

void	save_texture(char *str, int fd, t_data *datas)
{
	int	i;

	i = 0;
	while ((str && str[i] && str[i] == ' ') || (str[i] >= 9 && str[i] <= 13))
		i++;
	check_texture_info(i, str + i, fd, datas);
	free(str);
}
