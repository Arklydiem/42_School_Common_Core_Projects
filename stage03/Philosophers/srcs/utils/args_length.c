/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_length.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 14:43:38 by argomez           #+#    #+#             */
/*   Updated: 2022/09/14 15:42:26 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

static int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	return (index);
}

int	args_length(int argc, char **args)
{
	long int	number;
	int			index;
	int			length;

	index = 1;
	length = 0;
	while (index <= argc)
	{
		while (*args[index] == '0')
			args[index]++;
		length = ft_strlen(args[index]);
		if (length > 10)
			return (index);
		number = ft_atoi(args[index]);
		if (number > 2147483647)
			return (index);
		index++;
	}
	return (0);
}
