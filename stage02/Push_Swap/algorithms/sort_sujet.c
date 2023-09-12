/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_sujet.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:54:47 by argomez           #+#    #+#             */
/*   Updated: 2022/07/01 14:55:00 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	algo_sujet(t_tabs *tabs)
{
	swap_a(tabs);
	push_b(tabs);
	push_b(tabs);
	push_b(tabs);
	rotate_a(tabs);
	rotate_b(tabs);
	reverse_rotate_a_b(tabs);
	swap_a(tabs);
	push_a(tabs);
	push_a(tabs);
	push_a(tabs);
}
