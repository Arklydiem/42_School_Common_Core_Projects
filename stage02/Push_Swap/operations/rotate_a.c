/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_a.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:47:51 by argomez           #+#    #+#             */
/*   Updated: 2022/06/30 15:32:53 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	rotate_a(t_tabs *tabs)
{
	int	i;
	int	t;
	int	temp;

	i = -1;
	temp = tabs->a[0];
	while (++i < tabs->size_a - 1)
	{
		t = tabs->a[i];
		tabs->a[i] = tabs->a[i + 1];
		tabs->a[i + 1] = t;
	}
	tabs->a[tabs->size_a - 1] = temp;
	ft_printf("ra\n");
}
