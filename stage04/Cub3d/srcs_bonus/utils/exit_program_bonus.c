/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:47:39 by vnadal            #+#    #+#             */
/*   Updated: 2023/02/10 14:47:07 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

void	free_step_dist(double *step_dist_x,	double *step_dist_y)
{
	free(step_dist_x);
	free(step_dist_y);
}

int	exit_game(t_data *datas)
{
	free_program(datas);
	return (0);
}
