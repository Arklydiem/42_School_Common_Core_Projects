/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 12:39:33 by argomez           #+#    #+#             */
/*   Updated: 2022/08/18 14:56:02 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

//Includes :
# include "libft/libft.h"
# include <signal.h>

//Structures :
typedef struct s_data
{
	int			index_binaries_tab;
	int			binaries_tab[8];
	int			value;
	int			signals_zero_number;
	int			size_of_str;
	int			index_str;
	char		*str_to_print;
}	t_data;

//Prototypes :
void	signals_handler(int key, siginfo_t *infos, void *context);
void	initialise_datas(t_data *datas);

#endif