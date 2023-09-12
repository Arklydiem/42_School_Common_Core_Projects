/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:38:44 by argomez           #+#    #+#             */
/*   Updated: 2022/07/16 12:05:06 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	swap_a_b(t_tabs *tabs)
{
	int	temp;

	if (tabs->size_b < 2 || tabs->size_b < 2 )
		return ;
	temp = tabs->a[0];
	tabs->a[0] = tabs->a[1];
	tabs->a[1] = temp;
	temp = tabs->b[0];
	tabs->b[0] = tabs->b[1];
	tabs->b[1] = temp;
	ft_printf("ss\n");
}
