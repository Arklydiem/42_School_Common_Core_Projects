/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:56:53 by vnadal            #+#    #+#             */
/*   Updated: 2023/02/10 14:25:19 by vnadal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *nptr)
{
	int	res;
	int	sign;
	int	i;

	i = 0;
	res = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		res = res * 10 + (nptr[i] - 48);
		i++;
	}
	while (nptr[i] == ' ')
		i++;
	if (!(nptr[i] == '\n' || nptr[i] == '\0'))
		return (-1);
	return (res * sign);
}
