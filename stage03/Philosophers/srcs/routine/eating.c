/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:50:15 by argomez           #+#    #+#             */
/*   Updated: 2022/09/14 15:34:39 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static void	unblocking_fork(t_philos *philo)
{
	pthread_mutex_unlock(&philo->m_fork);
	if (philo->number == philo->datas->nb_philos)
		pthread_mutex_unlock(&philo->datas->philos[0].m_fork);
	else
		pthread_mutex_unlock(&philo->datas->philos[philo->number].m_fork);
}

static void	eating_time(t_philos *philo)
{
	pthread_mutex_lock(&philo->m_last_eat);
	print_messages(philo, 'e');
	philo->last_eat = get_time(philo);
	pthread_mutex_unlock(&philo->m_last_eat);
	better_mssleep(philo->datas, philo->datas->tt_eat);
	pthread_mutex_lock(&philo->m_nb_eat);
	philo->nb_eat--;
	pthread_mutex_unlock(&philo->m_nb_eat);
}

static void	blocking_fork(t_philos *philo)
{
	pthread_mutex_lock(&philo->m_fork);
	print_messages(philo, 'f');
	if (philo->number == philo->datas->nb_philos)
		pthread_mutex_lock(&philo->datas->philos[0].m_fork);
	else
		pthread_mutex_lock(&philo->datas->philos[philo->number].m_fork);
	print_messages(philo, 'f');
}

int	eating(t_philos *philo)
{
	pthread_mutex_lock(&philo->datas->m_is_ended);
	if (philo->datas->is_ended != 0)
	{
		pthread_mutex_unlock(&philo->datas->m_is_ended);
		return (1);
	}
	pthread_mutex_unlock(&philo->datas->m_is_ended);
	blocking_fork(philo);
	eating_time(philo);
	unblocking_fork(philo);
	return (0);
}
