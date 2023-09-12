/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:10:40 by argomez           #+#    #+#             */
/*   Updated: 2022/05/19 11:04:01 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*bloc;

	if (nmemb == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	bloc = malloc(nmemb * size);
	if (bloc == NULL)
		return (NULL);
	ft_bzero(bloc, nmemb * size);
	return (bloc);
}
