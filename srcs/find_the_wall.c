/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_the_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 10:54:37 by ocojeda-          #+#    #+#             */
/*   Updated: 2019/05/03 13:08:25 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void						calc_distance_to_wall(t_env *env, t_calc *calc)
{
	if (calc->side == 0)
		calc->wall = (calc->mapper_x - env->data.player_pos.v[1] +
		(1 - calc->step_x) / 2) / calc->ray.v[1];
	else
		calc->wall = (calc->mapper_y - env->data.player_pos.v[0] +
		(1 - calc->step_y) / 2) / calc->ray.v[0];
}

void						calc_line(t_calc *calc)
{
	calc->line_height = HEIGHT / calc->wall;
	calc->line_begin = (HEIGHT - calc->line_height + 1) / 2;
	if (calc->line_begin < 0)
		calc->line_begin = 0;
	calc->line_end = (calc->line_height + HEIGHT) / 2;
	if (calc->line_end >= HEIGHT)
		calc->line_end = HEIGHT;
}

void						map_texture(t_env *env, t_calc *calc)
{
	if (calc->side == 0)
		calc->wall_mapper = (env->data.player_pos.v[0] +
		calc->wall * calc->ray.v[0]);
	else
		calc->wall_mapper = (env->data.player_pos.v[1] +
		calc->wall * calc->ray.v[1]);
	calc->wall_mapper = calc->wall_mapper - (int)calc->wall_mapper;
	calc->text_x = calc->wall_mapper * env->data.text.w;
}

void						set_final_color(t_env *env, t_calc *calc)
{
	calc->color1.r = env->data.text.img[((calc->text_x +
	calc->tex_y * env->data.text.w) * env->data.text.opp)];
	calc->color1.g = env->data.text.img[((calc->text_x +
	calc->tex_y * env->data.text.w) * env->data.text.opp) + 1];
	calc->color1.b = env->data.text.img[((calc->text_x +
	calc->tex_y * env->data.text.w) * env->data.text.opp) + 2];
	if (env->data.color_option == 1)
		((unsigned int *)env->img_data)[calc->x +
		(calc->line_begin * LEN)] = ret_colors(calc->color1);
	else
		((unsigned int *)env->img_data)[calc->x +
		(calc->line_begin * LEN)] = color_determinator(calc);
}

void						find_the_wall(t_env *env)
{
	t_calc				calc;

	clear_img(env);
	calc.distance = vec3_normalize(vec3(HEIGHT, LEN, 0));
	calc.x = 0;
	while (calc.x++ < LEN)
	{
		set_base_calcs(env, &calc);
		if (env->data.color_option == 3)
			draw_map_sky(env, &calc);
		draw_wall(env, &calc);
		if (env->data.color_option == 3)
			draw_map_floor(env, &calc);
	}
}
