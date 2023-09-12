/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   import_images.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 15:04:18 by argomez           #+#    #+#             */
/*   Updated: 2022/06/02 15:07:54 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	import_images(t_game *g)
{
	import_chars(g);
	import_collects(g);
	import_escapes(g);
	import_numbers(g);
	import_sentinels(g);
	import_tiles(g);
	import_walls(g);
}
