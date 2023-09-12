/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnadal <vnadal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 10:09:38 by vnadal            #+#    #+#             */
/*   Updated: 2022/11/24 10:04:23 by vnadal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	char			*s_map;
	unsigned int	i;
	int				len;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	s_map = ft_calloc(len + 1, sizeof(char));
	if (!s_map)
		return (NULL);
	i = 0;
	while (s[i])
	{
		s_map[i] = (*f)(i, s[i]);
		i++;
	}
	return (s_map);
}
