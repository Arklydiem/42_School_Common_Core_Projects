/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lives.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:00:49 by argomez           #+#    #+#             */
/*   Updated: 2022/09/14 13:35:59 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static int	eater(t_philos *philo)
{
	eating(philo);
	pthread_mutex_lock(&philo->datas->m_is_ended);
	if (philo->datas->is_ended != 0)
	{
		pthread_mutex_unlock(&philo->datas->m_is_ended);
		return (1);
	}
	pthread_mutex_unlock(&philo->datas->m_is_ended);
	return (0);
}

static int	sleeper(t_philos *philo)
{
	sleeping(philo);
	pthread_mutex_lock(&philo->datas->m_is_ended);
	if (philo->datas->is_ended != 0)
	{
		pthread_mutex_unlock(&philo->datas->m_is_ended);
		return (1);
	}
	pthread_mutex_unlock(&philo->datas->m_is_ended);
	return (0);
}

static int	thinker(t_philos *philo)
{
	thinking(philo);
	pthread_mutex_lock(&philo->datas->m_is_ended);
	if (philo->datas->is_ended != 0)
	{
		pthread_mutex_unlock(&philo->datas->m_is_ended);
		return (1);
	}
	pthread_mutex_unlock(&philo->datas->m_is_ended);
	return (0);
}

void	*lives(void *args)
{
	t_philos	*philo;
	int			error;

	philo = (t_philos *)args;
	if (philo->number % 2 == 1)
		better_usleep(500);
	error = 0;
	while (1)
	{
		error = eater(philo);
		if (error == 1)
			return (NULL);
		error = sleeper(philo);
		if (error == 1)
			return (NULL);
		error = thinker(philo);
		if (error == 1)
			return (NULL);
	}
	return (NULL);
}
