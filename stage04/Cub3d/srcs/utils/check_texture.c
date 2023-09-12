/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnadal <vnadal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:55:00 by vnadal            #+#    #+#             */
/*   Updated: 2023/02/07 16:47:21 by vnadal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	check_empty_texture(t_texture texture)
{
	if (texture.ceiling && texture.floor
		&& texture.north && texture.south && texture.west)
		return (0);
	return (1);
}

int	check_textures_extension(t_texture texture)
{
	if (ft_extension(texture.east, ".xpm")
		&& ft_extension(texture.north, ".xpm")
		&& ft_extension(texture.south, ".xpm")
		&& ft_extension(texture.west, ".xpm"))
		return (1);
	return (0);
}

int	check_textures_rgb(t_texture texture)
{
	int	i;
	int	number;

	i = 0;
	while (texture.ceiling && texture.ceiling[i] && texture.ceiling[i][0])
		i++;
	if (i != 3)
		return (0);
	i = 0;
	while (texture.floor && texture.floor[i] && texture.floor[i][0])
		i++;
	if (i != 3)
		return (0);
	i = 0;
	while (i < 3 && texture.ceiling && texture.floor)
	{
		number = ft_atoi(texture.ceiling[i]);
		if (!(0 <= number && number <= 255))
			return (0);
		number = ft_atoi(texture.floor[i]);
		if (!(0 <= number && number <= 255))
			return (0);
		i++;
	}
	return (1);
}
