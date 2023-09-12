/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:12:15 by argomez           #+#    #+#             */
/*   Updated: 2022/09/14 15:05:23 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

int	check_args(int argc, char **args, int error)
{
	argc--;
	if (argc < 4 || argc > 5)
	{
		printf("Error : ");
		printf("Wrong number of argument\nMin 4 - Max 5 - Actual : %d", argc);
		return (1);
	}
	error = args_length(argc, args);
	if (error != 0)
	{
		printf("Error : The argument \"%d\" is too long.\n", error);
		return (1);
	}
	error = args_conformity(argc, args);
	if (error != 0)
	{
		printf("Error : The argument \"%d\" is not numeric.\n", error);
		return (1);
	}
	if (ft_atoi(args[1]) > 200 || ft_atoi(args[1]) < 1)
	{
		printf("Error : Incorrect number of philosophers. Min 1 - Max 200\n");
		return (1);
	}
	return (0);
}
