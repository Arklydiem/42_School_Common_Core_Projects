/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_tabs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 12:46:52 by argomez           #+#    #+#             */
/*   Updated: 2022/07/16 17:20:17 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	display_tabs(t_tabs *tabs)
{
	int	i;

	i = -1;
	while (tabs->size > ++i)
	{
		if (i >= tabs->size_a)
			printf("%11c", '.');
		else
			printf("%11d", (int)tabs->a[i]);
		if (i >= tabs->size_b)
			printf("%11c", '.');
		else
			printf("%11d", (int)tabs->b[i]);
		printf("\n");
	}
}
