/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:16:30 by argomez           #+#    #+#             */
/*   Updated: 2022/09/14 15:32:12 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	main(int argc, char **argv)
{
	t_datas	datas;

	if (check_args(argc, argv, 0) == 1)
		return (1);
	initialise_all(&datas, argc, argv);
	if (datas.nb_philos == 1)
	{
		printf("0 1 has taken a fork\n");
		better_usleep(datas.tt_die * 1000);
		printf("%d 1 is dead\n", datas.tt_die);
		return (0);
	}
	create_threads(&datas);
	join_threads(&datas);
	destroy_mutex(&datas);
	return (0);
}
