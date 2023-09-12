/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:55:00 by vnadal            #+#    #+#             */
/*   Updated: 2023/02/10 14:47:03 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	check_empty_texture(t_texture texture)
{
	if (texture.ceiling && texture.floor)
		return (0);
	return (1);
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
