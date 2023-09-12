/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:47:51 by argomez           #+#    #+#             */
/*   Updated: 2022/06/27 16:09:03 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	reverse_rotate_b(t_tabs *tabs)
{
	int	i;
	int	t;

	i = tabs->size_b;
	t = tabs->b[tabs->size_b - 1];
	while (i > 0)
	{
		tabs->b[i] = tabs->b[i] + tabs->b[i - 1];
		tabs->b[i - 1] = tabs->b[i] - tabs->b[i - 1];
		tabs->b[i] = tabs->b[i] - tabs->b[i - 1];
		i--;
	}
	tabs->b[0] = t;
	ft_printf("rrb\n");
}
