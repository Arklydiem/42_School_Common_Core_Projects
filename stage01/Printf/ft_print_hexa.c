/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 19:20:31 by argomez           #+#    #+#             */
/*   Updated: 2022/04/22 13:59:06 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hexa(unsigned int nb, char c, int *ptr)
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
	if (c == 'x')
		ft_print_nbr(n, "0123456789abcdef", ptr);
	else
		ft_print_nbr(n, "0123456789ABCDEF", ptr);
}
