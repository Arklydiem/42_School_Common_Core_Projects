/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 19:53:38 by argomez           #+#    #+#             */
/*   Updated: 2022/09/13 19:58:58 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	sleeping(t_philos *philo)
{
	pthread_mutex_lock(&philo->datas->m_is_ended);
	if (philo->datas->is_ended != 0)
	{
		pthread_mutex_unlock(&philo->datas->m_is_ended);
		return (1);
	}
	pthread_mutex_unlock(&philo->datas->m_is_ended);
	print_messages(philo, 's');
	better_mssleep(philo->datas, philo->datas->tt_sleep);
	return (0);
}
