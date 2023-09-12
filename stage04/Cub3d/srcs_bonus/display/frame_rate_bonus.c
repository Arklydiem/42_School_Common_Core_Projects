/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_rate_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:54:53 by vnadal            #+#    #+#             */
/*   Updated: 2023/02/10 14:46:01 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	frame_rate(t_data *datas)
{
	static long long	rate;

	fill_base(datas);
	manage_camera(datas);
	manage_render(datas);
	if (rate % 10 == 0)
	{
		datas->animation++;
		if (datas->animation > 15)
			datas->animation = 1;
		if (rate > 90000000000000)
			rate = 0;
	}
	rate++;
	return (0);
}
