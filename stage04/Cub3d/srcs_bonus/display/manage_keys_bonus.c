/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_keys_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:52:51 by vnadal            #+#    #+#             */
/*   Updated: 2023/02/10 14:46:09 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	manage_keys(int key, t_data *datas)
{
	if (key == XK_Escape)
		exit_game(datas);
	else if (key == XK_w || key == XK_Up)
		move_player_up(datas);
	else if (key == XK_s || key == XK_Down)
		move_player_down(datas);
	else if (key == XK_a)
		move_player_left(datas);
	else if (key == XK_d)
		move_player_right(datas);
	else if ((key == XK_Left || key == XK_q))
		rotate_player_left(datas);
	else if ((key == XK_Right || key == XK_e))
		rotate_player_right(datas);
	else if (key == XK_f)
		open_close_doors(datas);
	return (0);
}
