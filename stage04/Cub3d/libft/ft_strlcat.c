/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnadal <vnadal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 13:39:11 by vnadal            #+#    #+#             */
/*   Updated: 2022/11/24 09:43:57 by vnadal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlcat(char *dst, char *src, int size)
{
	int	len_dst;
	int	len_src;
	int	i;
	int	len_dstbase;

	i = 0;
	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	len_dst = ft_strlen(dst);
	len_dstbase = ft_strlen(dst);
	if (len_dst >= size)
		return (len_src + size);
	while (src[i] && len_dst < size - 1)
	{
		dst[len_dst] = src[i];
		i++;
		len_dst++;
	}
	dst[len_dst] = '\0';
	return (len_dstbase + len_src);
}
