/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:38:44 by argomez           #+#    #+#             */
/*   Updated: 2022/07/16 12:05:25 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	push_b(t_tabs *tabs)
{
	int	index;

	if (tabs->size_a < 1)
		return ;
	index = tabs->size_b;
	while (index-- > 0)
		tabs->b[index + 1] = tabs->b[index];
	tabs->b[0] = tabs->a[0];
	tabs->size_b++;
	index = -1;
	while (++index < tabs->size_a)
		tabs->a[index] = tabs->a[index + 1];
	tabs->size_a--;
	ft_printf("pb\n");
}
