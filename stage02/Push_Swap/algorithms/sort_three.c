/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 14:37:10 by argomez           #+#    #+#             */
/*   Updated: 2022/07/16 11:54:20 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	sort_three(t_tabs *t)
{
	if ((t->a[0] < t->a[1] && t->a[0] < t->a[2] && t->a[1] > t->a[2])
		|| (t->a[0] > t->a[1] && t->a[1] < t->a[2] && t->a[0] < t->a[2])
		|| (t->a[0] > t->a[1] && t->a[1] > t->a[2]))
		swap_a(t);
	if (t->a[0] > t->a[2] && t->a[1] < t->a[2])
		rotate_a(t);
	else if (t->a[0] < t->a[1] && t->a[1] > t->a[2])
		reverse_rotate_a(t);
}
