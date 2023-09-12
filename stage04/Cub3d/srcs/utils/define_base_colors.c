/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define_base_colors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnadal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:41:11 by vnadal            #+#    #+#             */
/*   Updated: 2023/02/03 10:41:45 by vnadal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	define_base_colors(t_data *datas)
{
	int	red;
	int	green;
	int	blue;

	red = ft_atoi(datas->textures.ceiling[0]);
	green = ft_atoi(datas->textures.ceiling[1]);
	blue = ft_atoi(datas->textures.ceiling[2]);
	datas->textures.ceiling_color = rgb_to_hexa_color(red, green, blue);
	red = ft_atoi(datas->textures.floor[0]);
	green = ft_atoi(datas->textures.floor[1]);
	blue = ft_atoi(datas->textures.floor[2]);
	datas->textures.floor_color = rgb_to_hexa_color(red, green, blue);
}
