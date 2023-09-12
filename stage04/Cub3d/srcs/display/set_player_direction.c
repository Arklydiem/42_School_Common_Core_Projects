/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_player_direction.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:19:48 by argomez           #+#    #+#             */
/*   Updated: 2023/02/10 14:31:14 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	set_player_direction(t_data *datas)
{
	char	c;

	c = datas->start;
	if (c == 'N')
	{
		datas->_player.x = 0;
		datas->_player.y = -1;
	}
	else if (c == 'S')
	{
		datas->_player.x = 0;
		datas->_player.y = 1;
	}
	else if (c == 'E')
	{
		datas->_player.x = 1;
		datas->_player.y = 0;
	}
	else if (c == 'W')
	{
		datas->_player.x = -1;
		datas->_player.y = 0;
	}
}
