/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnadal <vnadal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 10:32:46 by vnadal            #+#    #+#             */
/*   Updated: 2022/11/24 10:03:46 by vnadal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, int n)
{
	unsigned char	*tmp_dest;
	unsigned char	*tmp_src;
	int				i;

	if (!src && !dest)
		return (NULL);
	tmp_dest = (unsigned char *)dest;
	tmp_src = (unsigned char *)src;
	i = 0;
	if (tmp_dest < tmp_src)
		ft_memcpy(tmp_dest, tmp_src, n);
	else
	{
		while (i < n)
		{
			tmp_dest[n - 1 - i] = tmp_src[n - 1 - i];
			i++;
		}
	}
	return (dest);
}
