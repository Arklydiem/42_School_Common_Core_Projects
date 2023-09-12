/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 17:47:23 by argomez           #+#    #+#             */
/*   Updated: 2022/04/22 13:41:37 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (*str++)
		i++;
	return (i);
}

void	ft_print_nbr(unsigned long long nb, char *base, int *ptr)
{
	if (nb >= ft_strlen(base))
	{
		ft_print_nbr(nb / ft_strlen(base), base, ptr);
		ft_print_nbr(nb % ft_strlen(base), base, ptr);
	}
	else
		ft_print_char(base[nb], ptr);
}
