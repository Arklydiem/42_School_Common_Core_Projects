/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:14:45 by vnadal            #+#    #+#             */
/*   Updated: 2023/02/10 14:47:34 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

char	*find_text_error(int code_error)
{
	char	*errors[20];

	errors[0] = "Invalid number of arguments.";
	errors[1] = "Invalid map extension.";
	errors[2] = "Can't open the selected map.";
	errors[3] = "Invalid texture description of the map.";
	errors[4] = "Invalid definition of the map.";
	errors[5] = "Invalid extension for textures.";
	errors[6] = "Invalid rgb code for textures.";
	errors[7] = "Can't have more than one player.";
	errors[8] = "Invalid symbol on the map.";
	errors[9] = "Map not closed.";
	errors[10] = "One player needed in the map.";
	errors[11] = "Can't open the window.";
	errors[12] = "Can't load the texture.";
	errors[13] = "Doors must be between two walls.";
	errors[14] = "Textures corrupted.";
	errors[15] = "Resolution set is too small [1280:720 - 16:9].";
	errors[16] = "Texture already defined.";
	errors[17] = "Not Yet Implanted.";
	errors[18] = "Not Yet Implanted.";
	errors[19] = "Not Yet Implanted.";
	return (errors[code_error]);
}

void	ft_error(int code_error, int fd, t_data *datas)
{
	ft_printf_fd(2, "%s%sError :\n%s%s", UNDERLINE, T_RED, RESET, T_PURPLE);
	ft_printf_fd(2, "%s\n", find_text_error(code_error - 1));
	ft_printf_fd(2, "%s", RESET);
	close(fd);
	free_program(datas);
}
