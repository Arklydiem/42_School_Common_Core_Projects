/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 11:14:19 by argomez           #+#    #+#             */
/*   Updated: 2022/07/19 11:28:27 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	main(int argc, char **argv)
{
	t_tabs	*tabs;

	if (argc <= 1)
		return (0);
	tabs = malloc(sizeof(t_tabs));
	if (tabs == NULL)
		ft_error(tabs);
	init_tabs(tabs);
	args_conformity(tabs, argc, argv);
	find_size(tabs, argc, argv);
	fill_tab(tabs, argc, argv);
	check_formating(tabs);
	add_index(tabs);
	sort_tabs(tabs);
	ft_frees(tabs);
	return (0);
}
