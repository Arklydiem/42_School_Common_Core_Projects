/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_eats.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 16:00:49 by argomez           #+#    #+#             */
/*   Updated: 2022/09/14 14:15:39 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static int	eat_finder(t_datas *datas, int count, int index)
{
	t_philos	*philo;

	while (count < datas->nb_philos)
	{
		count = 0;
		index = 0;
		while (index < datas->nb_philos)
		{
			pthread_mutex_lock(&datas->m_is_ended);
			if (datas->is_ended == 1)
			{
				pthread_mutex_unlock(&datas->m_is_ended);
				return (1);
			}
			pthread_mutex_unlock(&datas->m_is_ended);
			philo = &datas->philos[index];
			pthread_mutex_lock(&philo->m_nb_eat);
			if (philo->nb_eat <= 0)
				count++;
			pthread_mutex_unlock(&philo->m_nb_eat);
			index++;
		}
	}
	return (0);
}

void	*check_eats(void *args)
{
	t_datas		*datas;

	datas = (t_datas *)args;
	eat_finder(datas, 0, 0);
	pthread_mutex_lock(&datas->m_is_ended);
	datas->is_ended = 1;
	pthread_mutex_unlock(&datas->m_is_ended);
	return (NULL);
}
