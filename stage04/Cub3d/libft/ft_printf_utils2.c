/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnadal <vnadal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 10:44:15 by vnadal            #+#    #+#             */
/*   Updated: 2022/11/24 10:02:05 by vnadal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_display_p(va_list lst, int fd)
{
	unsigned long int	p;

	p = va_arg(lst, unsigned long int);
	if (!p)
	{
		write(fd, "(nil)", 5);
		return ;
	}
	write(fd, "0x", 2);
	ft_ul_putlnbr_base(p, BASE_LOWER, fd);
}
