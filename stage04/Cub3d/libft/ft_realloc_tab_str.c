/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_tab_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnadal <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 10:51:03 by vnadal            #+#    #+#             */
/*   Updated: 2023/01/24 11:04:57 by vnadal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**realloc_tab_str(char **tab, char *str)
{
	int		i;
	char	**new_tab;

	i = 0;
	while (tab && tab[i] != NULL)
		i++;
	new_tab = malloc(sizeof(char *) * (i + 2));
	if (!new_tab)
		return (NULL);
	new_tab[i + 1] = NULL;
	i = 0;
	while (tab && tab[i] != NULL)
	{
		new_tab[i] = tab[i];
		i++;
	}
	if (tab)
		free(tab);
	new_tab[i] = str;
	return (new_tab);
}
