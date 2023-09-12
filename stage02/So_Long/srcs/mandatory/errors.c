/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:10:06 by argomez           #+#    #+#             */
/*   Updated: 2022/06/22 14:54:50 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static void	error_base(int error)
{
	char	*error_base[11];

	error_base[1] = "Wrong number of arguments";
	error_base[2] = "not yet defined";
	error_base[3] = "not yet defined";
	error_base[4] = "not yet defined";
	error_base[5] = "not yet defined";
	error_base[6] = "not yet defined";
	error_base[7] = "not yet defined";
	error_base[8] = "not yet defined";
	error_base[9] = "not yet defined";
	ft_printf("Base error : %s.\n", error_base[error]);
}

static void	error_map(int error)
{
	char	*error_map[11];

	error_map[0] = "Need a Map with '.ber' extension";
	error_map[1] = "At file opening";
	error_map[2] = "File Empty";
	error_map[3] = "At file closing";
	error_map[4] = "Map needs at least 3 lines";
	error_map[5] = "Map needs at least 3 colunms";
	error_map[6] = "Only walls can be on edges";
	error_map[7] = "The map is not rectangular";
	error_map[8] = "Unknown symbol on the map";
	error_map[9] = "Missing some symbols";
	ft_printf("Map error : %s.\n", error_map[error % 10]);
}

static void	error_display(int error)
{
	char	*error_display[11];

	error_display[0] = "display failed";
	error_display[1] = "not yed defined";
	error_display[2] = "not yed defined";
	error_display[3] = "not yed defined";
	error_display[4] = "not yed defined";
	error_display[5] = "not yed defined";
	error_display[6] = "not yed defined";
	error_display[7] = "not yed defined";
	error_display[8] = "not yed defined";
	error_display[9] = "not yed defined";
	ft_printf("Display error : %s.\n", error_display[error % 10]);
}

void	ft_error(int error, t_game *game)
{
	if (error == 0)
		return ;
	ft_printf("Error\n[ ERROR %d ] - ", error);
	if (1 <= error && error <= 9)
		error_base(error);
	else if (10 <= error && error <= 19)
		error_map(error);
	else if (20 <= error && error <= 29)
		error_display(error);
	clear_game(game);
}
