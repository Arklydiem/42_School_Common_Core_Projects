/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnadal <vnadal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 10:45:30 by vnadal            #+#    #+#             */
/*   Updated: 2022/11/24 10:04:40 by vnadal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char *s, int start, int len)
{
	char	*new_s;
	int		len_s;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start > len_s || len == 0)
	{
		new_s = ft_strdup("");
		return (new_s);
	}
	if ((start + len) > len_s)
	{
		new_s = ft_calloc((len_s - start + 1), sizeof(char));
		if (!new_s)
			return (NULL);
		ft_strlcpy(new_s, (s + start), (len_s - start + 1));
		return (new_s);
	}
	new_s = ft_calloc((len + 1), sizeof(char));
	if (!new_s)
		return (NULL);
	ft_strlcpy(new_s, (s + start), (len + 1));
	return (new_s);
}
