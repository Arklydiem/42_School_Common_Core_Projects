/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnadal <vnadal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 13:39:12 by vnadal            #+#    #+#             */
/*   Updated: 2022/11/24 10:04:15 by vnadal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		len_s1;
	int		len_s2;
	char	*new_s;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	new_s = ft_calloc(len_s1 + len_s2 + 1, sizeof(char));
	if (!new_s)
		return (NULL);
	ft_strlcpy(new_s, s1, (len_s1 + 1));
	ft_strlcat(new_s, s2, (len_s1 + len_s2 + 1));
	return (new_s);
}
