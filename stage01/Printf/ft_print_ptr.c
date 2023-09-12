/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:39:42 by argomez           #+#    #+#             */
/*   Updated: 2022/04/22 13:42:23 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_ptr(unsigned long long nb, int *ptr)
{
	if (nb == 0)
	{
		ft_print_str("(nil)", ptr);
		return ;
	}
	ft_print_str("0x", ptr);
	ft_print_nbr(nb, "0123456789abcdef", ptr);
}
