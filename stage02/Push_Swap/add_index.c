/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/07 14:31:17 by argomez           #+#    #+#             */
/*   Updated: 2022/07/16 12:04:54 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	add_index(t_tabs *tabs)
{
	long int	temp;
	int			index;
	int			i;

	index = -1;
	while (++index < tabs->size + 1)
	{
		i = -1;
		temp = 1111111111111;
		while (++i < tabs->size)
		{
			if (temp > tabs->a[i] && tabs->b[i] == 0)
				temp = tabs->a[i];
		}
		i = 0;
		while (temp != tabs->a[i])
			i++;
		tabs->b[i] = index;
	}
	index = -1;
	while (++index < tabs->size)
		tabs->a[index] = tabs->b[index];
}
