/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 16:58:51 by argomez           #+#    #+#             */
/*   Updated: 2022/05/19 11:08:16 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_atoi(const char *nptr)
{
	size_t	sign_c;
	int		is_neg;
	size_t	result;

	sign_c = 0;
	is_neg = 1;
	result = 0;
	while (*nptr != '\0' && (('\t' <= *nptr && *nptr <= '\r') || *nptr == ' '))
		nptr++;
	while (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			is_neg = -1;
		sign_c++;
		nptr++;
	}
	while ('0' <= *nptr && *nptr <= '9')
	{
		result *= 10;
		result += (*nptr - 48);
		nptr++;
	}
	if (sign_c > 1)
		return (0);
	return (result * is_neg);
}
