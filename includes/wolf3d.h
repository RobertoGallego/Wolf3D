/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 18:08:55 by ocojeda-          #+#    #+#             */
/*   Updated: 2019/05/03 13:07:16 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <stdio.h>
# include "../minilibx_macos/mlx.h"
# include "libmat4.h"
# include "libft.h"
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>

# define HEIGHT 720
# define LEN 840

typedef struct		s_color
{
	float			b;
	float			g;
	float			r;
	float			a;
}					t_color;

typedef struct		s_texture
{
	unsigned char	*img;
	int				size;
	int				w;
	int				h;
	int				sl;
	short			bpp;
	short			opp;
}					t_texture;

typedef struct		s_calc
{
	t_vec3			ray;
	t_vec3			distance;
	t_vec3			delta;
	t_vec3			plane;
	t_color			color1;
	float			wall;
	float			wall_mapper;
	float			cam_overx;
	int				step_x;
	int				step_y;
	int				mapper_x;
	int				mapper_y;
	int				side;
	int				line_height;
	int				line_begin;
	int				line_end;
	int				y;
	int				x;
	int				map_texty;
	unsigned int	color;
	int				text_x;
	int				tex_y;
}					t_calc;

typedef struct		s_data
{
	char			**map;
	int				border_map;
	int				final_border;
	int				ms;
	int				player;
	int				map_height;
	t_vec3			player_pos;
	t_vec3			cam_dir;
	t_vec3			plane;
	t_vec3			cam_rot;
	t_texture		text;
	int				color_option;
	char			p_exists;
}					t_data;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	int				bpp;
	int				sizeline;
	int				endian;
	t_data			data;
	char			*img_data;
}					t_env;

int					parse(t_env *env, char *filename);
void				init_data(t_env *env);
void				init_mlx(t_env *env);
void				find_the_wall(t_env *env);
float				set_degree(float deg);
void				put_mlx(t_env *env);
int					my_key_func(int keycode, t_env *env);
int					mouse_hook_escape(t_env *env);
int					mouse_hook_color(int button, int x, int y, t_env *env);
void				clear_img(t_env *env);
void				load_bmp(t_env *env, char *filename);
void				check_player_pos(t_data *data, int i, char *temp);
unsigned int		color_determinator(t_calc *calc);
unsigned int		color_determinator2(t_calc *calc);
unsigned int		ret_colors(t_color colo);
void				init_calc_data(t_env *env, t_calc *calc);
void				get_map2(t_data *data, int i);
int					wolf_line_checker(char *str, t_data *data);
int					wolf_line_checker2(char *str, t_data *data, int i);
void				set_base_calcs(t_env *env, t_calc *calc);
void				calc_distance_to_wall(t_env *env, t_calc *calc);
void				calc_line(t_calc *calc);
void				map_texture(t_env *env, t_calc *calc);
void				get_map2(t_data *data, int i);
int					wolf_line_checker(char *str, t_data *data);
int					wolf_line_checker2(char *str, t_data *data, int i);
int					check_file(char *str);
int					put_player_position(char *str, t_data *data);
void				fix_final_map(t_env *env);
float				maprange(float a1, float a2, float s);
void				draw_map_sky(t_env *env, t_calc *calc);
void				draw_map_floor(t_env *env, t_calc *calc);
void				draw_wall(t_env *env, t_calc *calc);
void				set_final_color(t_env *env, t_calc *calc);

#endif
