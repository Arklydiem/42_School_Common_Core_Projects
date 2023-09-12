/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_mouse_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 14:00:13 by vnadal            #+#    #+#             */
/*   Updated: 2023/02/10 14:46:12 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	calc_coeff(int x)
{
	if (x > WIDTH / 2)
		x = x - (WIDTH / 2);
	else
		x = (WIDTH / 2) - x;
	return (x * 1.15);
}

void	rotate_player_left_cam(t_data *datas, int coeff)
{
	double	old_player_x;
	double	old_plane_x;

	old_player_x = datas->_player.x;
	old_plane_x = datas->plane.x;
	datas->_player.x = datas->_player.x * cos(-(ROTATION_SPEED_CAM * coeff)) \
		- datas->_player.y * sin(-(ROTATION_SPEED_CAM * coeff));
	datas->_player.y = old_player_x * sin(-(ROTATION_SPEED_CAM * coeff)) \
		+ datas->_player.y * cos(-(ROTATION_SPEED_CAM * coeff));
	datas->plane.x = datas->plane.x * cos(-(ROTATION_SPEED_CAM * coeff)) \
		- datas->plane.y * sin(-ROTATION_SPEED_CAM * coeff);
	datas->plane.y = old_plane_x * sin(-(ROTATION_SPEED_CAM * coeff)) \
		+ datas->plane.y * cos(-(ROTATION_SPEED_CAM * coeff));
}

void	rotate_player_right_cam(t_data *datas, int coeff)
{
	double	old_player_x;
	double	old_plane_x;

	old_player_x = datas->_player.x;
	old_plane_x = datas->plane.x;
	datas->_player.x = datas->_player.x * cos(ROTATION_SPEED_CAM * coeff) \
		- datas->_player.y * sin(ROTATION_SPEED_CAM * coeff);
	datas->_player.y = old_player_x * sin(ROTATION_SPEED_CAM * coeff) \
		+ datas->_player.y * cos(ROTATION_SPEED_CAM * coeff);
	datas->plane.x = datas->plane.x * cos(ROTATION_SPEED_CAM * coeff) \
		- datas->plane.y * sin(ROTATION_SPEED_CAM * coeff);
	datas->plane.y = old_plane_x * sin(ROTATION_SPEED_CAM * coeff) \
		+ datas->plane.y * cos(ROTATION_SPEED_CAM * coeff);
}

void	manage_camera(t_data *datas)
{
	int	x;
	int	y;
	int	coeff;

	y = 0;
	x = 0;
	mlx_mouse_get_pos(datas->mlx.mlx, datas->mlx.window, &x, &y);
	coeff = calc_coeff(x);
	if (x < WIDTH / 2)
		rotate_player_left_cam(datas, coeff);
	else if (x > WIDTH / 2)
		rotate_player_right_cam(datas, coeff);
	mlx_mouse_move(datas->mlx.mlx, datas->mlx.window, WIDTH / 2, HEIGHT / 2);
}
