/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 13:17:10 by argomez           #+#    #+#             */
/*   Updated: 2022/07/16 12:55:54 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

//Includes
# include <stdlib.h>
# include "libft/libft.h"

//Structures
typedef struct s_tabs
{
	long int	*a;
	long int	*b;
	int			size;
	int			size_a;
	int			size_b;
	int			count;
}	t_tabs;

//Prototypes
void	init_tabs(t_tabs *tabs);
void	ft_error(t_tabs *tabs);
void	args_conformity(t_tabs *tabs, int argc, char **argv);
void	find_size(t_tabs *tabs, int argc, char **argv);
void	ft_frees(t_tabs *tabs);
void	fill_tab(t_tabs *tabs, int argc, char **argv);
void	check_formating(t_tabs *tabs);
void	display_tabs(t_tabs *tabs);
void	sort_tabs(t_tabs *tabs);
void	add_index(t_tabs *tabs);

//Opreation
void	swap_a(t_tabs *tabs);
void	swap_b(t_tabs *tabs);
void	swap_a_b(t_tabs *tabs);
void	push_a(t_tabs *tabs);
void	push_b(t_tabs *tabs);
void	rotate_a(t_tabs *tabs);
void	rotate_b(t_tabs *tabs);
void	rotate_a_b(t_tabs *tabs);
void	reverse_rotate_a(t_tabs *tabs);
void	reverse_rotate_b(t_tabs *tabs);
void	reverse_rotate_a_b(t_tabs *tabs);

//Algorythms
void	algo_sujet(t_tabs *tabs);
void	sort_three(t_tabs *t);
void	sort_four(t_tabs *t);
void	sort_five(t_tabs *t);
void	sort_others(t_tabs *t);

#endif
