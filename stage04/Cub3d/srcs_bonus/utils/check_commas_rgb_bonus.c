/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_commas_rgb_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 12:37:39 by argomez           #+#    #+#             */
/*   Updated: 2023/02/10 15:08:22 by vnadal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d_bonus.h"

int	check_commas_in_rgb(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ',' && str[i] == str[i + 1])
			return (FALSE);
		i++;
	}
	while (str[i] != ',')
		i--;
	if (ft_isdigit(str[i + 1]) == FALSE)
		return (FALSE);
	if (str[ft_strlen(str) - 1] == ',')
		return (FALSE);
	return (TRUE);
}
