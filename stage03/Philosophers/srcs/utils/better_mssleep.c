/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   better_mssleep.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:44:47 by argomez           #+#    #+#             */
/*   Updated: 2022/09/14 13:53:33 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static int	calculate_time_diff(struct timeval start, struct timeval actual)
{
	long long int	sec;
	long long int	usec;
	long long int	result;

	sec = actual.tv_sec - start.tv_sec;
	usec = actual.tv_usec - start.tv_usec;
	result = (sec * 1000000) + usec;
	return ((int)(result / 1000));
}

void	better_mssleep(t_datas *datas, long int mssec)
{
	struct timeval	start;
	struct timeval	actual;
	int				time;

	gettimeofday(&start, NULL);
	while (1)
	{
		pthread_mutex_lock(&datas->m_is_ended);
		if (datas->is_ended != 0)
		{
			pthread_mutex_unlock(&datas->m_is_ended);
			break ;
		}
		pthread_mutex_unlock(&datas->m_is_ended);
		gettimeofday(&actual, NULL);
		time = calculate_time_diff(start, actual);
		if (time >= mssec)
			break ;
	}
}
