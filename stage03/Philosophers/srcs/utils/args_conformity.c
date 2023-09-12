/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_conformity.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:07:17 by argomez           #+#    #+#             */
/*   Updated: 2022/09/14 15:43:24 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	check_char(char *str, int index)
{
	char	*tab;
	int		i;

	tab = "0123456789+ ";
	i = 0;
	while (i < 12)
	{
		if (str[index] == tab[i])
		{
			if (str[index] != ' ' && str[index + 1] == '+')
				return (0);
			return (1);
		}
		i++;
	}
	return (0);
}

static int	check_string(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (check_char(str, i) == 0)
			return (0);
		i++;
	}
	return (1);
}

int	args_conformity(int argc, char **args)
{
	int	i;

	i = 0;
	while (++i <= argc)
	{
		if (check_string(args[i]) == 0)
			return (i);
	}
	return (0);
}
