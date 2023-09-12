/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnadal <vnadal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 13:11:06 by vnadal            #+#    #+#             */
/*   Updated: 2022/11/24 10:02:01 by vnadal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlstr(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(fd, "(null)", 6);
		return ;
	}
	while (s[i])
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
}

void	ft_putlnbr(int n, int fd)
{
	char		sign;
	long int	res;

	res = (long int)n;
	if (res < 0)
	{
		sign = '-';
		res = res * -1;
		ft_putchar_fd(sign, fd);
	}
	if (res >= 10)
		ft_putlnbr((res / 10), fd);
	ft_putchar_fd((res % 10 + '0'), fd);
}

void	ft_us_putlnbr(unsigned int n, int fd)
{
	if (n >= 10)
		ft_us_putlnbr((n / 10), fd);
	ft_putchar_fd((n % 10 + '0'), fd);
}

void	ft_ul_putlnbr_base(unsigned long int nbr, char *base, int fd)
{
	unsigned long int	base_fd;

	base_fd = 16;
	if (nbr >= base_fd)
		ft_ul_putlnbr_base(nbr / base_fd, base, fd);
	ft_putchar_fd(base[nbr % base_fd], fd);
}
