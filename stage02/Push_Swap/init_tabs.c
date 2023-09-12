/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tabs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 17:03:18 by argomez           #+#    #+#             */
/*   Updated: 2022/06/30 15:25:59 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_tabs(t_tabs *tabs)
{
	tabs->a = NULL;
	tabs->b = NULL;
	tabs->size = 0;
	tabs->size_a = 0;
	tabs->size_b = 0;
	tabs->count = 0;
}
