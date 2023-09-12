/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: argomez <argomez@student.42angouleme.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 09:54:24 by vnadal            #+#    #+#             */
/*   Updated: 2023/02/10 14:53:41 by argomez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "../colors.h"

# define WIDTH 1920
# define HEIGHT 1080
# define NAME "Khouyes3D"
# define ROTATION_SPEED 0.01
# define MS 0.1
# define TRUE 1
# define FALSE 0

typedef struct s_mlx
{
	void	*mlx;
	void	*window;
}	t_mlx;

typedef struct s_image
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_image;

typedef struct s_texture
{
	char	*north;
	t_image	n_wall;
	char	*south;
	t_image	s_wall;
	char	*west;
	t_image	w_wall;
	char	*east;
	t_image	e_wall;
	char	**floor;
	char	**ceiling;
	int		floor_color;
	int		ceiling_color;
}	t_texture;

typedef struct s_coordinate
{
	double	x;
	double	y;
}	t_coordinate;

typedef struct s_int
{
	int	x;
	int	y;
}	t_int;

typedef struct s_data
{
	char			**map;
	t_int			tile;
	t_coordinate	player;
	t_coordinate	_player;
	t_coordinate	plane;
	t_coordinate	_ray;
	t_mlx			mlx;
	t_texture		textures;
	t_image			screen;
	double			perp_wall_dist;
	int				wall_height;
	double			texture_pos;
	int				texture_x;
	int				texture_y;
	int				side;
	int				x_count;
	char			start;
}	t_data;

// SRCS :
void	ft_error(int code_error, int fd, t_data *datas);
void	free_program(t_data *datas);
void	init_datas(t_data *datas);

// Parsing :
int		ft_extension(const char *str, const char *ext);
void	manage_file(char *str, t_data *datas);
void	check_map_validity(t_data *datas);
void	map_is_closed(t_data *datas);

// Display :

void	manage_display(t_data *datas);
void	set_coordinates(t_data *datas);
void	set_player_position(t_data *datas);
void	set_player_direction(t_data *datas);
double	calcul_delta_dist_x(t_data *datas);
double	calcul_delta_dist_y(t_data *datas);
double	*calculate_step_dist_x(double deltaDistX, t_data *datas);
double	*calculate_step_dist_y(double deltaDistY, t_data *datas);
double	calcul_perp_wall_dist(int side, double *step_dist_x, \
	double *step_dist_y, double deltaDist_X_Y[2]);
void	fill_column(int start, int end, t_data *datas, t_image *texture);
void	fill_base(t_data *datas);
int		manage_keys(int key, t_data *datas);
void	manage_render(t_data *datas);
void	move_player_up(t_data *datas);
void	move_player_down(t_data *datas);
void	move_player_right(t_data *datas);
void	move_player_left(t_data *datas);
void	rotate_player_left(t_data *datas);
void	rotate_player_right(t_data *datas);
void	load_textures(t_data *datas);

// Utils :

int		check_empty_line(char *str);
void	save_texture(char *str, int fd, t_data *datas);
int		check_textures_extension(t_texture texture);
int		check_textures_rgb(t_texture texture);
int		check_empty_texture(t_texture texture);
char	*skip_empty_lines(int fd, t_data *datas);
void	check_arround_spaces(int y, int x, t_data *datas);
void	check_inner_map(int y, int x, t_data *datas);
int		check_multiple_char(const char *str, char c);
double	ft_abs(double number);
int		rgb_to_hexa_color(int red, int green, int blue);
void	define_base_colors(t_data *datas);
int		exit_game(t_data *datas);
void	free_step_dist(double *step_dist_x,	double *step_dist_y);
int		frame_rate(t_data *datas);
t_image	find_texture(t_data *datas, int side);
int		check_commas_in_rgb(char *str);

#endif
