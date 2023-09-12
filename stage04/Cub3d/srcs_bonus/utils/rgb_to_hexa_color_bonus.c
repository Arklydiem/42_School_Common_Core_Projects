/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_hexa_color_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:58:24 by argomez           #+#    #+#             */
/*   Updated: 2023/02/10 14:47:18 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	rgb_to_hexa_color(int red, int green, int blue)
{
	int	color;

	color = (red << 16 | green << 8 | blue);
	return (color);
}
