/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnadal <vnadal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 18:33:53 by vnadal            #+#    #+#             */
/*   Updated: 2022/10/28 14:58:53 by vnadal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*joined;
	char		*line;
	char		*first;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	first = NULL;
	joined = ft_read_fd(fd, first);
	if (!joined)
		return (NULL);
	if (joined[0] == '\0')
	{
		free(joined);
		return (NULL);
	}
	line = ft_get_line(joined);
	free(joined);
	return (line);
}

char	*ft_read_fd(int fd, char *first)
{
	char	*read_s;
	int		nb_read;
	int		flag_end;

	flag_end = 1;
	read_s = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_s)
		return (NULL);
	while (ft_search_end(first) == 1 && flag_end == 1)
	{
		nb_read = read(fd, read_s, BUFFER_SIZE);
		if (nb_read < 0)
		{
			free(read_s);
			return (NULL);
		}
		if (nb_read < BUFFER_SIZE)
			flag_end = 0;
		read_s[nb_read] = '\0';
		first = ft_strjoin_gnl(first, read_s);
	}
	free(read_s);
	return (first);
}

char	*ft_get_line(char *joined)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (joined[i] && joined[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	j = 0;
	while (j <= i)
	{
		line[j] = joined[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}
