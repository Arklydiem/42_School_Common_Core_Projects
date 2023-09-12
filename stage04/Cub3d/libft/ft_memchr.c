/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnadal <vnadal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 14:26:51 by vnadal            #+#    #+#             */
/*   Updated: 2022/11/24 10:03:18 by vnadal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, int n)
{
	unsigned char	*tmp_s;
	int				i;

	i = 0;
	tmp_s = (unsigned char *)s;
	while (i < n)
	{
		if (tmp_s[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
