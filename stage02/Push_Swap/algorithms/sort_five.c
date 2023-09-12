/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:51:30 by argomez           #+#    #+#             */
/*   Updated: 2022/07/16 12:04:05 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	sort_five(t_tabs *t)
{
	int	index;

	index = 0;
	while (t->a[index] != 5)
		index++;
	if (index <= 2)
	{
		while (t->a[0] != 5)
			rotate_a(t);
		push_b(t);
		sort_four(t);
		push_a(t);
		rotate_a(t);
	}
	else
	{
		while (t->a[0] != 5)
			reverse_rotate_a(t);
		push_b(t);
		sort_four(t);
		push_a(t);
		rotate_a(t);
	}
}
