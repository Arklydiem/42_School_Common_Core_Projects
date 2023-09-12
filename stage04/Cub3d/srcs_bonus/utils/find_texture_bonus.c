/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_texture_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:47:01 by argomez           #+#    #+#             */
/*   Updated: 2023/02/10 14:47:09 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static t_image	find_dark_texture(t_data *datas)
{
	if (datas->animation == 1)
		return (datas->textures._dark[0]);
	if (datas->animation == 2)
		return (datas->textures._dark[1]);
	if (datas->animation == 3)
		return (datas->textures._dark[2]);
	if (datas->animation == 4)
		return (datas->textures._dark[3]);
	if (datas->animation == 5)
		return (datas->textures._dark[4]);
	if (datas->animation == 6)
		return (datas->textures._dark[5]);
	if (datas->animation == 7)
		return (datas->textures._dark[6]);
	return (datas->textures._dark[0]);
}

static t_image	find_light_texture(t_data *datas)
{
	if (datas->animation == 1)
		return (datas->textures._light[0]);
	if (datas->animation == 2)
		return (datas->textures._light[1]);
	if (datas->animation == 3)
		return (datas->textures._light[2]);
	if (datas->animation == 4)
		return (datas->textures._light[3]);
	if (datas->animation == 5)
		return (datas->textures._light[4]);
	if (datas->animation == 6)
		return (datas->textures._light[5]);
	if (datas->animation == 7)
		return (datas->textures._light[6]);
	return (datas->textures._light[0]);
}

t_image	find_texture(t_data *datas, int side)
{
	if (side == 1 && datas->hit == 2)
		return (find_light_texture(datas));
	else if (side == 0 && datas->hit == 2)
		return (find_dark_texture(datas));
	else if (side == 1 && datas->hit == 1)
		return (datas->textures._light[0]);
	else
		return (datas->textures._dark[0]);
}
