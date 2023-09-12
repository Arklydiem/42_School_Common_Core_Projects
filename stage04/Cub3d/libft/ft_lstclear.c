/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnadal <vnadal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:09:47 by vnadal            #+#    #+#             */
/*   Updated: 2022/10/03 09:27:15 by vnadal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp_list;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		tmp_list = *lst;
		(*del)(tmp_list->content);
		*lst = (*lst)->next;
		free(tmp_list);
	}
}
