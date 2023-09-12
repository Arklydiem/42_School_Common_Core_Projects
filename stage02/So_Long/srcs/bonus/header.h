/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 17:52:08 by argomez           #+#    #+#             */
/*   Updated: 2022/06/07 17:21:11 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

//Other Includes
# include "../../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <time.h>
# include "../../libft/libft.h"

//Structures
typedef struct s_entity
{
	int	x;
	int	y;
	int	state;
}	t_entity;

typedef struct s_map
{
	char		*name;
	int			x;
	int			y;
	char		**matrix;
	int			nb_starts;
	int			nb_escapes;
	int			nb_collects;
	t_entity	*player;
	t_entity	*sentinel;
	int			count_collects;
	int			count_moves;
	int			b;
	int			ex;
	int			ey;
	int			key;
}	t_map;

typedef struct s_mlx
{
	void	*m;
	void	*w;
}	t_mlx;

typedef struct s_img
{
	void	*i;
	char	*p;
	int		w;
	int		h;
}	t_img;

typedef struct s_game
{
	t_map	*map;
	t_mlx	*mlx;
	t_img	*w;
	t_img	*t;
	t_img	*c;
	t_img	*e;
	t_img	*left;
	t_img	*up;
	t_img	*right;
	t_img	*down;
	t_img	*n;
	t_img	*s;
}	t_game;

//Prototypes
void	ft_error(int error, t_game *game);

//Initialisation prototypes
void	game_init(t_game *game);
void	map_init(t_map *map);

//Clear prototypes
void	clear_game(t_game *game);
void	clear_images(t_game *game);

//Maps Prototypes
void	map_inspector(char **files, t_game *game);
void	check_map_symbols(char *line, int y, t_game *game);
void	change_matrix(t_game *g);

//Import_images
void	import_images(t_game *g);
void	import_chars(t_game *g);
void	import_collects(t_game *g);
void	import_escapes(t_game *g);
void	import_numbers(t_game *g);
void	import_sentinels(t_game *g);
void	import_tiles(t_game *g);
void	import_walls(t_game *g);

//Displays Prototypes
void	open_window(t_game *game);
void	print_images(t_game *game);
void	print_start_end(t_game *g, int y, int x, char c);
void	move_player(int key, t_game *g);
void	move_sentinel(t_game *g);
void	print_tiles(t_game *g, int y, int x, char c);
void	delcase(t_game *g, int x, int y);
void	newchar(t_game *g, int x, int y, int key);
void	print_up_1(t_game *g, int y, int x, char c);
void	print_down_1(t_game *g, int y, int x, char c);
void	print_left_1(t_game *g, int y, int x, char c);
void	print_right_1(t_game *g, int y, int x, char c);
void	print_up_2(t_game *g, int y, int x, char c);
void	print_down_2(t_game *g, int y, int x, char c);
void	print_left_2(t_game *g, int y, int x, char c);
void	print_right_2(t_game *g, int y, int x, char c);
void	display_count(t_game *g, int count);
void	choose_sentinels(t_game *g);

void	print_player(t_game *g, t_entity *e);
void	print_collects(t_game *g, int y, int x, char p);
void	print_escape(t_game *g, int y, int x, int b);
void	print_tiles(t_game *g, int y, int x, char c);
void	print_trees(t_game *g, int y, int x);
void	print_walls(t_game *g, int y, int x);
void	print_collects(t_game *g, int y, int x, char p);
void	print_collects(t_game *g, int y, int x, char p);
void	print_sentinels(t_game *g);

//Moves
void	move_entities(int key, t_game *g);
int		able_to_move(t_game *g, int y, int x);
void	reset_case(t_game *g, t_entity *e);
void	push_entity(t_game *g, t_entity *e, int key);
int		player_on_sentinel(t_entity *p, t_entity *s);
int		player_on_escape(t_game *g, t_entity *p);
void	apply_case(t_game *g, t_entity *e, int key);

//New
void	print_sentinel(t_game *g, t_entity *e, char cell);
void	print_player_up(t_game *g, t_entity *e, char cell);
void	print_player_down(t_game *g, t_entity *e, char cell);
void	print_player_left(t_game *g, t_entity *e, char cell);
void	print_player_right(t_game *g, t_entity *e, char cell);
void	put_image_entity(t_game *g, t_img *i, t_entity *e, int j);

#endif
