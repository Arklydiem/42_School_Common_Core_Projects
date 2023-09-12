/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_keys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:52:51 by vnadal            #+#    #+#             */
/*   Updated: 2023/02/10 14:32:27 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	manage_keys(int key, t_data *datas)
{
	if (key == XK_Escape)
		exit_game(datas);
	if (key == XK_w || key == XK_Up)
		move_player_up(datas);
	else if (key == XK_s || key == XK_Down)
		move_player_down(datas);
	else if (key == XK_a)
		move_player_left(datas);
	else if (key == XK_d)
		move_player_right(datas);
	else if (key == XK_Left || key == XK_q)
		rotate_player_left(datas);
	else if (key == XK_Right || key == XK_e)
		rotate_player_right(datas);
	return (0);
}
