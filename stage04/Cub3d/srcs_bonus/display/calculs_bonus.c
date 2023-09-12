/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculs_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:25:48 by argomez           #+#    #+#             */
/*   Updated: 2023/02/10 14:45:37 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

double	calcul_delta_dist_x(t_data *datas)
{
	if (datas->_ray.x == 0)
		return (exp(30));
	else
		return (fabs(1 / datas->_ray.x));
}

double	calcul_delta_dist_y(t_data *datas)
{
	if (datas->_ray.y == 0)
		return (exp(30));
	else
		return (fabs(1 / datas->_ray.y));
}

double	*calculate_step_dist_x(double deltaDistX, t_data *datas)
{
	double	*step_dist_x;

	step_dist_x = malloc(sizeof(double) * 2);
	if (datas->_ray.x < 0)
	{
		step_dist_x[0] = -1;
		step_dist_x[1] = (datas->player.x - (double)datas->tile.x) * deltaDistX;
	}
	else
	{
		step_dist_x[0] = 1;
		step_dist_x[1] = ((double)datas->tile.x + 1.0 - datas->player.x) \
			* deltaDistX;
	}
	return (step_dist_x);
}

double	*calculate_step_dist_y(double deltaDistY, t_data *datas)
{
	double	*step_dist_y;

	step_dist_y = malloc(sizeof(double) * 2);
	if (datas->_ray.y < 0)
	{
		step_dist_y[0] = -1;
		step_dist_y[1] = (datas->player.y - (double)datas->tile.y) * deltaDistY;
	}
	else
	{
		step_dist_y[0] = 1;
		step_dist_y[1] = ((double)datas->tile.y + 1.0 - datas->player.y) \
			* deltaDistY;
	}
	return (step_dist_y);
}

double	calcul_perp_wall_dist(int side, double *step_dist_x, \
		double *step_dist_y, double deltaDist_X_Y[2])
{
	if (side == 0)
		return (step_dist_x[1] - deltaDist_X_Y[0]);
	else
		return (step_dist_y[1] - deltaDist_X_Y[1]);
}
