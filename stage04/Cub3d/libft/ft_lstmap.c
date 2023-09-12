/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnadal <vnadal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 19:39:58 by vnadal            #+#    #+#             */
/*   Updated: 2022/10/03 09:27:39 by vnadal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_l;
	t_list	*tmp_elem;

	if (!f || !del)
		return (NULL);
	new_l = NULL;
	while (lst)
	{
		tmp_elem = ft_lstnew((*f)(lst->content));
		if (!tmp_elem)
		{
			ft_lstclear(&new_l, del);
			return (NULL);
		}
		ft_lstadd_back(&new_l, tmp_elem);
		lst = lst->next;
	}
	return (new_l);
}
