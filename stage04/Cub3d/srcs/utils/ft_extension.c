/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extension.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:29:41 by vnadal            #+#    #+#             */
/*   Updated: 2023/01/27 15:53:30 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_extension(const char *str, const char *ext)
{
	int	str_len;
	int	ext_len;

	str_len = ft_strlen((char *)str);
	ext_len = ft_strlen((char *)ext);
	if (str_len <= ext_len)
		return (0);
	while (str_len-- > 0 && ext_len-- > 0)
	{
		if (str[str_len] != ext[ext_len])
			return (0);
	}
	if (str[str_len] == '/')
		return (0);
	return (1);
}
