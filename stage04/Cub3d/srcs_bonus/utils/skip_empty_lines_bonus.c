/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skip_empty_lines_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:52:29 by argomez           #+#    #+#             */
/*   Updated: 2023/02/10 14:47:25 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

char	*skip_empty_lines(int fd, t_data *datas)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			ft_error(5, fd, datas);
		}
		if (!check_empty_line(line))
			return (line);
		free(line);
	}
}
