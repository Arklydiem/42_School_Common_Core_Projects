/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:29:24 by argomez           #+#    #+#             */
/*   Updated: 2022/04/22 14:52:01 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(char *str, int *ptr)
{
	if (!str)
	{
		ft_print_str("(null)", ptr);
		return ;
	}
	while (*str)
		ft_print_char(*str++, ptr);
}
