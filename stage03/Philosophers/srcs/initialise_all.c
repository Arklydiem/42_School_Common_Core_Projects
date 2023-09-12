/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_all.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:09:12 by argomez           #+#    #+#             */
/*   Updated: 2022/08/22 17:06:57 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

static void	initialise_philosophers(t_datas *datas)
{
	int			index;
	t_philos	*philo;

	index = 0;
	while (index < datas->nb_philos)
	{
		philo = &datas->philos[index];
		philo->datas = datas;
		pthread_mutex_init(&philo->m_number, NULL);
		philo->number = index + 1;
		pthread_mutex_init(&philo->m_last_eat, NULL);
		pthread_mutex_init(&philo->m_fork, NULL);
		pthread_mutex_init(&philo->m_nb_eat, NULL);
		philo->nb_eat = datas->eats;
		index++;
	}
}

void	initialise_all(t_datas *datas, int argc, char **args)
{
	datas->nb_philos = (int)ft_atoi(args[1]);
	datas->tt_die = (int)ft_atoi(args[2]);
	datas->tt_eat = (int)ft_atoi(args[3]);
	datas->tt_sleep = (int)ft_atoi(args[4]);
	if (argc - 1 == 5)
		datas->eats = (int)ft_atoi(args[5]);
	else
		datas->eats = -1;
	datas->is_ended = 0;
	pthread_mutex_init(&datas->m_is_ended, NULL);
	pthread_mutex_init(&datas->m_print, NULL);
	initialise_philosophers(datas);
}
