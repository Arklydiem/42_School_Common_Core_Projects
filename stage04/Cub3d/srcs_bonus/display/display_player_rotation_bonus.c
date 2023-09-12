/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   display_player_rotation.c                          :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: vnadal <marvin@42.fr>					  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/02/09 15:22:59 by vnadal			#+#	#+#			 */
/*   Updated: 2023/02/09 15:29:06 by vnadal           ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "../cub3d_bonus.h"

static void	draw_pixel(t_data *datas, t_coordinate pos)
{
	char	*pixel;

	pixel = datas->screen.addr + ((int)pos.y * datas->screen.line_length \
		+ (int)pos.x * (datas->screen.bits_per_pixel / 8));
	*(unsigned int *)pixel = 0xffffff;
}

static void	draw_line(t_data *datas, t_coordinate *start, t_coordinate *end)
{
	t_coordinate	delta;
	t_coordinate	pos_inc;
	t_coordinate	current_pos;
	float			longest_side_len;
	int				i;

	i = 0;
	delta.x = (end->x - start->x);
	delta.y = (end->y - start->y);
	longest_side_len = fmax(fabs(delta.x), fabs(delta.y));
	pos_inc.x = delta.x / longest_side_len;
	pos_inc.y = delta.y / longest_side_len;
	current_pos.x = start->x;
	current_pos.y = start->y;
	while (i < longest_side_len)
	{
		draw_pixel(datas, current_pos);
		current_pos.x += pos_inc.x;
		current_pos.y += pos_inc.y;
		i++;
	}
}

void	display_player_direction(t_data *datas)
{
	t_coordinate	n;
	t_coordinate	start;

	start.x = WIDTH - 90;
	start.y = 90;
	n.x = start.x + (10 * datas->_player.x);
	n.y = start.y + (10 * datas->_player.y);
	draw_line(datas, &start, &n);
}
