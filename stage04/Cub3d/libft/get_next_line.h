/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnadal <vnadal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/07 18:06:54 by vnadal            #+#    #+#             */
/*   Updated: 2022/11/24 10:05:33 by vnadal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
int		ft_strlen(char *s);
int		ft_search_end(char *line);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_get_line(char *joined);
char	*ft_save_after(char *joined);
char	*ft_read_fd(int fd, char *save_after);

#endif
