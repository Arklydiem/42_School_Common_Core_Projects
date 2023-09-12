/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:47:51 by argomez           #+#    #+#             */
/*   Updated: 2022/07/01 14:52:27 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	rotate_b(t_tabs *tabs)
{
	int	i;
	int	t;
	int	temp;

	i = -1;
	temp = tabs->b[0];
	while (++i < tabs->size_b - 1)
	{
		t = tabs->b[i];
		tabs->b[i] = tabs->b[i + 1];
		tabs->b[i + 1] = t;
	}
	tabs->b[tabs->size_b - 1] = temp;
	ft_printf("rb\n");
}
