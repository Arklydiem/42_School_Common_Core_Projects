/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnadal <vnadal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:39:05 by vnadal            #+#    #+#             */
/*   Updated: 2022/11/24 10:05:55 by vnadal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_search_end(char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (line[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		len_new_s;
	char	*new_s;
	int		i;
	int		j;

	len_new_s = ft_strlen(s1) + ft_strlen(s2);
	new_s = malloc((len_new_s + 1) * sizeof(char));
	if (!new_s)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (s1 && s1[i])
	{
		new_s[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] && i < len_new_s)
		new_s[i++] = s2[j++];
	free(s1);
	new_s[i] = '\0';
	return (new_s);
}
