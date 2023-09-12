/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_messages.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/27 14:11:01 by argomez           #+#    #+#             */
/*   Updated: 2022/09/14 13:52:04 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static void	printing(t_philos *philo, char action, int number, long timestamp)
{
	pthread_mutex_lock(&philo->datas->m_is_ended);
	if (philo->datas->is_ended != 0)
	{
		pthread_mutex_unlock(&philo->datas->m_is_ended);
		pthread_mutex_unlock(&philo->datas->m_print);
		return ;
	}
	pthread_mutex_unlock(&philo->datas->m_is_ended);
	if (action == 'f')
		printf("%ld %d has taken a fork\n", timestamp, number);
	else if (action == 'e')
		printf("%ld %d is eating\n", timestamp, number);
	else if (action == 's')
		printf("%ld %d is sleeping\n", timestamp, number);
	else if (action == 't')
		printf("%ld %d is thinking\n", timestamp, number);
	else if (action == 'd')
		printf("%ld %d is dead\n", timestamp, number);
	pthread_mutex_unlock(&philo->datas->m_print);
}

void	print_messages(t_philos *philo, char action)
{
	int		number;
	long	timestamp;

	pthread_mutex_lock(&philo->datas->m_is_ended);
	if (philo->datas->is_ended != 0)
	{
		pthread_mutex_unlock(&philo->datas->m_is_ended);
		return ;
	}
	pthread_mutex_unlock(&philo->datas->m_is_ended);
	pthread_mutex_lock(&philo->datas->m_print);
	pthread_mutex_lock(&philo->m_number);
	number = philo->number;
	pthread_mutex_unlock(&philo->m_number);
	timestamp = get_time(philo);
	printing(philo, action, number, timestamp);
}
