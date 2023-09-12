/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:51:50 by argomez           #+#    #+#             */
/*   Updated: 2022/06/07 17:35:51 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	game = ft_calloc(1, sizeof(t_game));
	game_init(game);
	if (argc < 2)
		ft_error(1, game);
	map_inspector(++argv, game);
	change_matrix(game);
	open_window(game);
	clear_game(game);
	return (0);
}
