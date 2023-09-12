/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 16:01:49 by vnadal            #+#    #+#             */
/*   Updated: 2023/01/30 10:30:01 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printf_fd(int fd, char *s, ...)
{
	va_list	lst;
	int		i;

	va_start(lst, s);
	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			ft_display_flags(fd, s[i], lst);
		}
		else
			ft_putchar_fd(s[i], fd);
		i++;
	}
	va_end(lst);
}

void	ft_display_flags(int fd, char s, va_list lst)
{
	if (s == 'c')
		ft_putchar_fd(va_arg(lst, int), fd);
	else if (s == '%')
		ft_putchar_fd(s, fd);
	else if (s == 's')
		ft_putlstr((va_arg(lst, char *)), fd);
	else if (s == 'd' || s == 'i')
		ft_putlnbr((va_arg(lst, int)), fd);
	else if (s == 'x')
		ft_ul_putlnbr_base((va_arg(lst, unsigned int)), BASE_LOWER, fd);
	else if (s == 'X')
		ft_ul_putlnbr_base((va_arg(lst, unsigned int)), BASE_CAPS, fd);
	else if (s == 'u')
		ft_us_putlnbr((va_arg(lst, unsigned int)), fd);
	else if (s == 'p')
		ft_display_p(lst, fd);
	else
	{
		ft_putchar_fd('%', fd);
		ft_putchar_fd(s, fd);
	}
}
