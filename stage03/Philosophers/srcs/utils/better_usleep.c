/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   better_usleep.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:44:47 by argomez           #+#    #+#             */
/*   Updated: 2022/09/13 21:00:12 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static int	calculate_time_diff(struct timeval actual, struct timeval wainting)
{
	long long int	sec;
	long long int	usec;
	long long int	result;

	gettimeofday(&wainting, NULL);
	sec = wainting.tv_sec - actual.tv_sec;
	usec = wainting.tv_usec - actual.tv_usec;
	result = (sec * 1000000) + usec;
	return ((int)result);
}

void	better_usleep(long int usec)
{
	struct timeval	actual;
	struct timeval	waiting;

	gettimeofday(&actual, NULL);
	while (calculate_time_diff(actual, waiting) < usec)
		continue ;
}
