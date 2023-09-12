/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:51:29 by vnadal            #+#    #+#             */
/*   Updated: 2023/02/10 14:47:38 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	main(int argc, char **argv)
{
	t_data	datas;

	init_datas(&datas);
	if (argc != 2)
		ft_error(1, 0, &datas);
	if (WIDTH < 1280 || HEIGHT < 720)
		ft_error(16, 0, &datas);
	if (!ft_extension(argv[1], ".cub"))
		ft_error(2, 0, &datas);
	manage_file(argv[1], &datas);
	manage_display(&datas);
	free_program(&datas);
}
