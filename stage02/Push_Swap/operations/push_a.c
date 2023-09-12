/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:38:44 by argomez           #+#    #+#             */
/*   Updated: 2022/07/16 11:48:57 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	push_a(t_tabs *tabs)
{
	int	index;

	if (tabs->size_b < 1)
		return ;
	index = tabs->size_a;
	while (index-- > 0)
		tabs->a[index + 1] = tabs->a[index];
	tabs->a[0] = tabs->b[0];
	tabs->size_a++;
	index = -1;
	while (++index < tabs->size_b)
		tabs->b[index] = tabs->b[index + 1];
	tabs->size_b--;
	ft_printf("pa\n");
}
