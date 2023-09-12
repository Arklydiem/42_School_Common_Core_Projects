/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnadal <vnadal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:00:10 by vnadal            #+#    #+#             */
/*   Updated: 2022/10/03 11:29:43 by vnadal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_size(long int n)
{
	int	size;

	size = 0;
	if (n <= 0)
	{
		size++;
		n = n * -1;
	}
	while (n > 0)
	{
		n = n / 10;
		size++;
	}
	return (size);
}

char	*ft_itoa(int n)
{
	int			size_n;
	char		*convert_n;
	long int	res;

	res = (long int)n;
	size_n = ft_get_size(res);
	convert_n = malloc((size_n + 1) * sizeof(char));
	if (!convert_n)
		return (NULL);
	convert_n[size_n] = '\0';
	size_n--;
	if (res < 0)
	{
		convert_n[0] = '-';
		res = res * -1;
	}
	if (res == 0)
		convert_n[0] = '0';
	while (res > 0)
	{
		convert_n[size_n] = (res % 10) + 48;
		res = res / 10;
		size_n--;
	}
	return (convert_n);
}
