/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_decimal.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:42:00 by argomez           #+#    #+#             */
/*   Updated: 2022/04/21 18:29:56 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_decimal(int nb, int *ptr)
{
	size_t	n;

	if (nb == 0)
	{
		ft_print_char('0', ptr);
		return ;
	}
	if (nb < 0)
	{
		ft_print_char('-', ptr);
		n = nb;
		n *= -1;
	}
	else
		n = nb;
	ft_print_nbr(n, "0123456789", ptr);
}
