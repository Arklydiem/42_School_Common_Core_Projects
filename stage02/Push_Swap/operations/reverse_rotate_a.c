/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:47:51 by argomez           #+#    #+#             */
/*   Updated: 2022/07/01 14:52:41 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	reverse_rotate_a(t_tabs *tabs)
{
	int	i;
	int	t;
	int	temp;

	i = tabs->size_a;
	temp = tabs->a[tabs->size_a - 1];
	while (--i > 0)
	{
		t = tabs->a[i];
		tabs->a[i] = tabs->a[i - 1];
		tabs->a[i - 1] = t;
	}
	tabs->a[0] = temp;
	ft_printf("rra\n");
}
