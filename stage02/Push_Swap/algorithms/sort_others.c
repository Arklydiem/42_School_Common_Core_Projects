/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_others.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 14:36:20 by argomez           #+#    #+#             */
/*   Updated: 2022/07/16 17:37:50 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

// static int	is_one_in_bit(t_tabs *tabs, int index)
// {
// 	int i;

// 	i = 0;
// 	while (i < tabs->size_b)
// 	{
// 		if (!(tabs->a[0] & (1 << (index + 1))))
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

static void	push_bits(t_tabs *tabs, int index)
{
	int	i;

	i = -1;
	while (++i < tabs->size)
	{
		if (!(tabs->a[0] & (1 << index)))
			push_b(tabs);
		else
			rotate_a(tabs);
	}
}

// static void	push_back_bits_one_index(t_tabs *tabs, int index)
// {
// 	int	i;

// 	i = tabs->size_b - 1;
// 	while (i--)
// 	{
// 		if ((tabs->b[0] & (1 << index)))
// 		{
// 			push_a(tabs);
// 			rotate_a(tabs);
// 		}
// 		else
// 			rotate_b(tabs);
// 	}
// }

void	sort_others(t_tabs *tabs)
{
	int	index;

	index = 0;
	while (index < 32)
	{
		push_bits(tabs, index++);
		while (tabs->size_b > 0)
			push_a(tabs);
		if (is_tab_sorted(tabs->a, tabs->size_a) == 1)
			return ;
	}
}
