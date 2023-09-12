/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:45:32 by argomez           #+#    #+#             */
/*   Updated: 2022/04/22 15:19:28 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_afterpercent(va_list params, char *str, int *ptr)
{
	if (*str == 'c')
		ft_print_char(va_arg(params, int), ptr);
	else if (*str == 's')
		ft_print_str(va_arg(params, char *), ptr);
	else if (*str == 'p')
		ft_print_ptr(va_arg(params, unsigned long long), ptr);
	else if (*str == 'd' || *str == 'i')
		ft_print_decimal(va_arg(params, int), ptr);
	else if (*str == 'u')
		ft_print_unsigned(va_arg(params, unsigned int), ptr);
	else if (*str == 'x' || *str == 'X')
		ft_print_hexa(va_arg(params, unsigned int), *str, ptr);
	else if (*str == '%')
		ft_print_char('%', ptr);
	else
		return (0);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	params;
	char	*str;
	int		i;
	int		*ptr;

	i = 0;
	ptr = &i;
	va_start(params, format);
	str = (char *)format;
	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			if (ft_afterpercent(params, str, ptr) == 0)
				return (0);
		}
		else
			ft_print_char(*str, ptr);
		str++;
	}
	va_end(params);
	return (i);
}

/*int	main(void)
{
	char	c = 'a';
	char	s[] = "Bonjour";
	int		d = 1337;
	int		i = -2147483648;
	int		hex = 987654321;
	int		heX = 987654321;
	void	*ptr;

	ptr = &i;

	printf("\n%d\n\n",printf("%c", c));
	printf("\n%d\n\n", ft_printf("%c", c));

	printf("%s\n", s);
	printf("\n%d\n\n", ft_printf("%s", s));

	printf("%p\n", ptr);
	printf("\n%d\n\n", ft_printf("%p", ptr));

	printf("%d\n", d);
	printf("\n%d\n\n", ft_printf("%d", d));

	printf("%i\n", i);
	printf("\n%d\n\n", ft_printf("%i", i));

	printf("%u\n", i);
	printf("\n%d\n\n", ft_printf("%u", i));
	printf("%u\n", d);
	printf("\n%d\n\n", ft_printf("%u", d));

	printf("%x\n", hex);
	printf("\n%d\n\n", ft_printf("%x", hex));
	printf("%X\n", heX);
	printf("\n%d\n\n", ft_printf("%X", heX));

	return (0);
}*/
