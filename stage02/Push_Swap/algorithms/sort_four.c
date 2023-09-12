/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_four.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:51:30 by argomez           #+#    #+#             */
/*   Updated: 2022/07/16 12:03:55 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	sort_four(t_tabs *t)
{
	int	index;

	index = 0;
	while (t->a[index] != 4)
		index++;
	if (index <= 1)
	{
		while (t->a[0] != 4)
			rotate_a(t);
		push_b(t);
		sort_three(t);
		push_a(t);
		rotate_a(t);
	}
	else
	{
		while (t->a[0] != 4)
			reverse_rotate_a(t);
		push_b(t);
		sort_three(t);
		push_a(t);
		rotate_a(t);
	}
}
