/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_tabs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:14:47 by argomez           #+#    #+#             */
/*   Updated: 2022/07/16 16:54:27 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	sort_tabs(t_tabs *tabs)
{
	if (is_tab_sorted(tabs->a, tabs->size_a))
		return ;
	if (tabs->size == 2)
		swap_a(tabs);
	else if (tabs->size == 3)
		sort_three(tabs);
	else if (tabs->size == 4)
		sort_four(tabs);
	else if (tabs->size == 5)
		sort_five(tabs);
	else
		sort_others(tabs);
}
