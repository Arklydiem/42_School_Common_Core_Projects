/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_deaths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:00:49 by argomez           #+#    #+#             */
/*   Updated: 2022/09/14 14:07:40 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static int	death_finder(t_datas *datas, int index)
{
	long int	timestamp;
	t_philos	*philo;

	philo = &datas->philos[index];
	pthread_mutex_lock(&philo->m_last_eat);
	timestamp = get_time(philo);
	if (timestamp - philo->last_eat > datas->tt_die)
	{
		print_messages(philo, 'd');
		pthread_mutex_lock(&datas->m_is_ended);
		datas->is_ended = 1;
		pthread_mutex_unlock(&datas->m_is_ended);
		pthread_mutex_unlock(&philo->m_last_eat);
		return (1);
	}
	pthread_mutex_unlock(&philo->m_last_eat);
	pthread_mutex_lock(&datas->m_is_ended);
	if (datas->is_ended == 1)
	{
		pthread_mutex_unlock(&datas->m_is_ended);
		return (1);
	}
	pthread_mutex_unlock(&datas->m_is_ended);
	return (0);
}

void	*check_deaths(void *args)
{
	t_datas		*datas;
	int			index;
	int			error;

	datas = (t_datas *)args;
	error = 0;
	while (1)
	{
		index = 0;
		while (index < datas->nb_philos)
		{
			error = death_finder(datas, index);
			if (error == 1)
				return (NULL);
			index++;
		}
	}
	return (NULL);
}
