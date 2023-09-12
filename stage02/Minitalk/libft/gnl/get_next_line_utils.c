/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:45:54 by argomez           #+#    #+#             */
/*   Updated: 2022/08/12 13:06:01 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin_malloc(char *s1, char *s2)
{
	char	*result;
	size_t	size;
	size_t	size_s1;
	size_t	size_s2;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	size = size_s1 + size_s2;
	result = ft_calloc(sizeof(char), (size + 5));
	if (!result)
		return (NULL);
	while (*s1)
		*result++ = *s1++;
	free(s1 - size_s1);
	while (*s2)
		*result++ = *s2++;
	return (result - size);
}
