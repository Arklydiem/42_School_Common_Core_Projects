/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:07:49 by argomez           #+#    #+#             */
/*   Updated: 2022/09/12 18:20:09 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

long int	get_time(t_philos *philo)
{
	struct timeval	time_start;
	struct timeval	time_actual;
	long int		sec;
	long int		usec;
	long int		result;

	gettimeofday(&time_actual, NULL);
	time_start = philo->datas->starttime;
	sec = time_actual.tv_sec - time_start.tv_sec;
	usec = time_actual.tv_usec - time_start.tv_usec;
	result = (sec * 1000000) + usec;
	result /= 1000;
	return (result);
}
