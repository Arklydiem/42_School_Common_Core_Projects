/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:38:44 by argomez           #+#    #+#             */
/*   Updated: 2022/07/16 12:05:12 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	swap_b(t_tabs *tabs)
{
	int	temp;

	if (tabs->size_b < 2)
		return ;
	temp = tabs->b[0];
	tabs->b[0] = tabs->b[1];
	tabs->b[1] = temp;
	ft_printf("sb\n");
}
