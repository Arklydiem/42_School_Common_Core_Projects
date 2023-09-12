/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnadal <vnadal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:02:47 by vnadal            #+#    #+#             */
/*   Updated: 2022/11/24 09:42:25 by vnadal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(int nmemb, int size)
{
	unsigned char	*memloc;

	if (size == 0 || nmemb == 0)
	{
		memloc = malloc(sizeof(char) * 1);
		if (!memloc)
			return (NULL);
		memloc[0] = '\0';
		return (memloc);
	}
	if (nmemb > 2147483647 || size > 2147483647)
		return (NULL);
	if ((nmemb * size) > 2147483647)
		return (NULL);
	memloc = malloc(nmemb * size);
	if (!memloc)
		return (NULL);
	ft_bzero(memloc, (nmemb * size));
	return (memloc);
}
