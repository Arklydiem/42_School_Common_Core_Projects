/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 21:36:46 by argomez           #+#    #+#             */
/*   Updated: 2022/04/22 14:47:38 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//Includes
# include <stdarg.h>
# include <stddef.h>
# include <unistd.h>
# include <stdio.h>

//Prototypes
int		ft_printf(const char *format, ...);
void	ft_print_char(char c, int *ptr);
void	ft_print_str(char *str, int *ptr);
void	ft_print_nbr(unsigned long long nb, char *base, int *ptr);
void	ft_print_decimal(int nb, int *ptr);
void	ft_print_hexa(unsigned int nb, char c, int *ptr);
void	ft_print_ptr(unsigned long long nb, int *ptr);
void	ft_print_unsigned(unsigned int nb, int *ptr);

#endif
