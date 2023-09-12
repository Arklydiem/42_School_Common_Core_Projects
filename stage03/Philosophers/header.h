/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:39:33 by argomez           #+#    #+#             */
/*   Updated: 2022/09/14 14:53:30 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

//Includes :
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

//Structures :
struct	s_datas;

typedef struct s_philos
{
	struct s_datas	*datas;
	pthread_mutex_t	m_number;
	int				number;
	pthread_mutex_t	m_last_eat;
	int				last_eat;
	pthread_mutex_t	m_fork;
	pthread_mutex_t	m_nb_eat;
	int				nb_eat;
	pthread_t		philo;
}	t_philos;

typedef struct s_datas
{
	int				nb_philos;
	t_philos		philos[250];
	int				tt_die;
	int				tt_eat;
	int				tt_sleep;
	int				eats;
	pthread_t		check_eats;
	struct timeval	starttime;
	pthread_t		check_deaths;
	int				is_ended;
	pthread_mutex_t	m_is_ended;
	pthread_mutex_t	m_print;
}	t_datas;

//ROUTINE - Prototypes :
void			*check_deaths(void *args);
void			*check_eats(void *args);
void			*lives(void *args);
int				eating(t_philos *philo);
int				sleeping(t_philos *philo);
int				thinking(t_philos *philo);

//UTILS - Prototypes :
void			better_mssleep(t_datas *datas, long int mssec);
void			better_usleep(long int usec);
long long int	ft_atoi(char *nptr);
long int		get_time(t_philos *philo);
void			print_messages(t_philos *philo, char action);
int				args_conformity(int argc, char **args);
int				args_length(int argc, char **args);
int				check_args(int argc, char **args, int error);

//SRCS - Prototypes :
void			create_threads(t_datas *datas);
void			join_threads(t_datas *datas);
void			destroy_mutex(t_datas *datas);
void			initialise_all(t_datas *datas, int argc, char **args);

#endif