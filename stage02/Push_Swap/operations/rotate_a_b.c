/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:47:51 by argomez           #+#    #+#             */
/*   Updated: 2022/07/01 14:53:27 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	rotate_a_b(t_tabs *tabs)
{
	int	i;
	int	t;

	i = -1;
	while (++i < tabs->size_a - 1)
	{
		t = tabs->a[0];
		tabs->a[i] = tabs->a[i + 1];
		tabs->a[i + 1] = t;
	}
	tabs->a[i - 1] = t;
	i = -1;
	while (++i < tabs->size_b - 1)
	{
		t = tabs->b[0];
		tabs->b[i] = tabs->b[i + 1];
		tabs->b[i + 1] = t;
	}
	tabs->b[i - 1] = t;
	ft_printf("rr\n");
}
