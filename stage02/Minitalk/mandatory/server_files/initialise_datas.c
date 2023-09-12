/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialise_datas.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:24:57 by argomez           #+#    #+#             */
/*   Updated: 2022/08/18 13:25:49 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../header.h"

void	initialise_datas(t_data *datas)
{
	datas->str_to_print = NULL;
	datas->index_binaries_tab = 0;
	datas->binaries_tab[0] = 0;
	datas->binaries_tab[1] = 0;
	datas->binaries_tab[2] = 0;
	datas->binaries_tab[3] = 0;
	datas->binaries_tab[4] = 0;
	datas->binaries_tab[5] = 0;
	datas->binaries_tab[6] = 0;
	datas->binaries_tab[7] = 0;
	datas->signals_zero_number = 0;
	datas->index_str = -1;
	datas->size_of_str = 0;
}
