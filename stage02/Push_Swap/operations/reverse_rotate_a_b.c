/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:47:51 by argomez           #+#    #+#             */
/*   Updated: 2022/07/01 14:53:10 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	reverse_rotate_a_b(t_tabs *tabs)
{
	int	i;
	int	t;

	i = tabs->size_a;
	t = tabs->a[tabs->size_a - 1];
	while (i > 0)
	{
		tabs->a[i] = tabs->a[i] + tabs->a[i - 1];
		tabs->a[i - 1] = tabs->a[i] - tabs->a[i - 1];
		tabs->a[i] = tabs->a[i] - tabs->a[i - 1];
		i--;
	}
	tabs->a[0] = t;
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
	ft_printf("rrr\n");
}
