/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 13:47:01 by argomez           #+#    #+#             */
/*   Updated: 2023/02/06 13:47:14 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_image	find_texture(t_data *datas, int side)
{
	if (datas->_ray.x < 0 && side == 0)
		return (datas->textures.e_wall);
	else if (datas->_ray.x > 0 && side == 0)
		return (datas->textures.w_wall);
	else if (datas->_ray.y > 0 && side == 1)
		return (datas->textures.n_wall);
	else
		return (datas->textures.s_wall);
}
