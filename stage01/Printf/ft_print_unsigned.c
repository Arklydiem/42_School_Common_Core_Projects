/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 13:23:57 by argomez           #+#    #+#             */
/*   Updated: 2022/04/22 14:56:39 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_unsigned(unsigned int nb, int *ptr)
{
	if (nb == 4294967295)
		ft_print_str("4294967295", ptr);
	else if (nb < 0)
		ft_print_char('0', ptr);
	else if (nb > 4294967295)
		ft_print_nbr(4294967295, "0123456789", ptr);
	else
		ft_print_nbr(nb, "0123456789", ptr);
}
