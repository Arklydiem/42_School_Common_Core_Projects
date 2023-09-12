/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:52:13 by argomez           #+#    #+#             */
/*   Updated: 2022/09/14 13:07:44 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	create_threads(t_datas *datas)
{
	int			index;
	t_philos	*philo;

	index = 0;
	gettimeofday(&datas->starttime, NULL);
	while (index < datas->nb_philos)
	{
		philo = &datas->philos[index];
		philo->last_eat = get_time(philo);
		pthread_create(&philo->philo, NULL, lives, philo);
		index++;
	}
	pthread_create(&datas->check_deaths, NULL, check_deaths, datas);
	if (datas->eats > 0)
		pthread_create(&datas->check_eats, NULL, check_eats, datas);
}

void	join_threads(t_datas *datas)
{
	int			index;
	t_philos	*philo;

	index = 0;
	while (index < datas->nb_philos)
	{
		philo = &datas->philos[index];
		pthread_join(philo->philo, NULL);
		index++;
	}
	pthread_join(datas->check_deaths, NULL);
	if (datas->eats > 0)
		pthread_join(datas->check_eats, NULL);
}

void	destroy_mutex(t_datas *datas)
{
	int			index;
	t_philos	*philo;

	index = 0;
	while (index < datas->nb_philos)
	{
		philo = &datas->philos[index];
		pthread_mutex_destroy(&philo->m_number);
		pthread_mutex_destroy(&philo->m_fork);
		pthread_mutex_destroy(&philo->m_last_eat);
		pthread_mutex_destroy(&philo->m_nb_eat);
		index++;
	}
	pthread_mutex_destroy(&datas->m_print);
	pthread_mutex_destroy(&datas->m_is_ended);
}
