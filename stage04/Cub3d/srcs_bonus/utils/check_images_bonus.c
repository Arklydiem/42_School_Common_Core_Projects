/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_images_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 18:08:23 by argomez           #+#    #+#             */
/*   Updated: 2023/02/10 14:46:56 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	check_images(t_data *datas)
{
	t_image	*light;
	t_image	*dark;
	int		i;

	light = datas->textures._light;
	dark = datas->textures._dark;
	i = 0;
	while (i < 7)
	{
		if (!light[i].img || !dark[i].img)
			return (0);
		i++;
	}
	return (1);
}
