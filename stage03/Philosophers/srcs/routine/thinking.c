/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:04:44 by argomez           #+#    #+#             */
/*   Updated: 2022/09/13 00:02:36 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	thinking(t_philos *philo)
{
	pthread_mutex_lock(&philo->datas->m_is_ended);
	if (philo->datas->is_ended != 0)
	{
		pthread_mutex_unlock(&philo->datas->m_is_ended);
		return (1);
	}
	pthread_mutex_unlock(&philo->datas->m_is_ended);
	print_messages(philo, 't');
	return (0);
}
