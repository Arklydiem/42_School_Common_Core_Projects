/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnadal <vnadal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 15:15:22 by vnadal            #+#    #+#             */
/*   Updated: 2022/11/24 09:49:17 by vnadal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_word_size(char *s, char c)
{
	int	j;

	j = 0;
	while (!(s[j] == c) && s[j])
		j++;
	return (j);
}

static int	ft_get_word_count(char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			count++;
		while (s[i] && !(s[i] == c))
			i++;
	}
	return (count);
}

char	**ft_split(char *s, char c)
{
	char	**s_split;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	s_split = ft_calloc ((ft_get_word_count(s, c) + 1), sizeof(char *));
	if (!s_split)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			s_split[j] = ft_substr(s, i, ft_word_size(s + i, c));
			j++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	s_split[j] = NULL;
	return (s_split);
}
