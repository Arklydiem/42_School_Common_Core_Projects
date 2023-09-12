/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_empty_line_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:19:07 by vnadal            #+#    #+#             */
/*   Updated: 2023/02/10 14:46:50 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	check_empty_line(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
	{
		if (str[i] != ' ' && (str[i] < 9 || str[i] > 13))
			return (0);
		i++;
	}
	return (1);
}
