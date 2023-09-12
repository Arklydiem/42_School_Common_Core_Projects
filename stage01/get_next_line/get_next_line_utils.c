/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:45:54 by argomez           #+#    #+#             */
/*   Updated: 2022/04/28 22:49:08 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr(const char *s, const char c)
{
	if (!s)
		return (0);
	else
	{
		while (*s)
		{
			if (*s == c)
				return (1);
			s++;
		}
		return (0);
	}
}

char	*ft_strjoin_malloc(char *s1, char *s2)
{
	char	*result;
	size_t	size;
	size_t	size_s1;
	size_t	size_s2;

	size_s1 = ft_strlen(s1);
	size_s2 = ft_strlen(s2);
	size = size_s1 + size_s2;
	result = ft_calloc(sizeof(char), (size + 1));
	if (!result)
		return (NULL);
	while (*s1)
		*result++ = *s1++;
	free(s1 - size_s1);
	while (*s2)
		*result++ = *s2++;
	free(s2 - size_s2);
	return (result - size);
}

char	*ft_strdup(char *s)
{
	char	*result;
	size_t	size;

	size = ft_strlen(s);
	result = ft_calloc(sizeof(char), (size + 1));
	if (!result)
		return (NULL);
	while (*s)
		*result++ = *s++;
	return (result - size);
}

char	*ft_calloc(size_t nmemb, size_t size)
{
	char	*bloc;
	size_t	i;

	bloc = malloc(nmemb * size);
	if (!bloc)
		return (NULL);
	i = 0;
	while (i < size)
		bloc[i++] = '\0';
	return (bloc);
}
