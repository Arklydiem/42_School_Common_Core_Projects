/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 23:25:57 by argomez           #+#    #+#             */
/*   Updated: 2022/04/28 14:22:28 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

//Other Includes
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

//Prototypes
char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
int		ft_strchr(const char *s, const char c);
char	*ft_strjoin_malloc(char *s1, char *s2);
char	*ft_strdup(char *s);
char	*ft_calloc(size_t nmemb, size_t size);

#endif
