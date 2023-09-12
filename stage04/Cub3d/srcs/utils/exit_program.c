/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_program.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnadal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:47:39 by vnadal            #+#    #+#             */
/*   Updated: 2023/02/03 10:51:50 by vnadal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
