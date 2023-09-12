/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_formating.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 11:55:47 by argomez           #+#    #+#             */
/*   Updated: 2022/07/16 16:49:18 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	check_formating(t_tabs *tabs)
{
	int	i;
	int	j;

	i = -1;
	while (++i < tabs->size_a)
	{
		j = i;
		while (++j < tabs->size_a)
		{
			if (tabs->a[i] == tabs->a[j])
				ft_error(tabs);
		}
		if (tabs->a[i] < -2147483648 || tabs->a[i] > 2147483647)
			ft_error(tabs);
	}
}
