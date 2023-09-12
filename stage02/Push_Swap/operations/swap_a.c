/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:38:44 by argomez           #+#    #+#             */
/*   Updated: 2022/07/16 11:00:36 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	swap_a(t_tabs *tabs)
{
	int	temp;

	if (tabs->size_a < 2)
		return ;
	temp = tabs->a[0];
	tabs->a[0] = tabs->a[1];
	tabs->a[1] = temp;
	ft_printf("sa\n");
}
