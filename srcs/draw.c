/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 12:53:49 by ocojeda-          #+#    #+#             */
/*   Updated: 2019/05/03 13:07:07 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void						draw_map_sky(t_env *env, t_calc *calc)
{
	int		y;
	float	tmp;

	y = -1;
	while (++y < calc->line_end)
	{
		tmp = 2 * maprange(0, HEIGHT, calc->line_end);
		if (calc->side == 0)
			calc->text_x = ((env->data.player_pos.v[0] +
			calc->wall * calc->ray.v[0])) * env->data.text.w;
		else
			calc->text_x = ((env->data.player_pos.v[1] +
			calc->wall * calc->ray.v[1])) * env->data.text.w;
		calc->tex_y = y * tmp;
		while (calc->tex_y > env->data.text.h)
			calc->tex_y -= (env->data.text.h);
		calc->color1.r = env->data.text.img[((calc->text_x +
			(calc->tex_y) * env->data.text.w) * env->data.text.opp)];
		calc->color1.g = env->data.text.img[((calc->text_x +
			(calc->tex_y) * env->data.text.w) * env->data.text.opp) + 1];
		calc->color1.b = env->data.text.img[((calc->text_x +
			(calc->tex_y) * env->data.text.w) * env->data.text.opp) + 2];
		((unsigned int *)env->img_data)[calc->x +
			(y * LEN)] = ret_colors(calc->color1);
	}
}

void						draw_map_floor(t_env *env, t_calc *calc)
{
	float	tmp;

	tmp = 2 * maprange(0, HEIGHT, calc->line_end);
	while (calc->line_begin < HEIGHT)
	{
		if (calc->side == 0)
			calc->text_x = ((env->data.player_pos.v[0] +
			calc->wall * calc->ray.v[0])) * env->data.text.w;
		else
			calc->text_x = ((env->data.player_pos.v[1] +
			calc->wall * calc->ray.v[1])) * env->data.text.w;
		calc->tex_y = calc->line_begin * tmp;
		while (calc->tex_y > env->data.text.h)
			calc->tex_y -= (env->data.text.h);
		calc->color1.r = env->data.text.img[((calc->text_x +
		(calc->tex_y) * env->data.text.w) * env->data.text.opp)];
		calc->color1.g = env->data.text.img[((calc->text_x +
		(calc->tex_y) * env->data.text.w) * env->data.text.opp) + 1];
		calc->color1.b = env->data.text.img[((calc->text_x +
			(calc->tex_y) * env->data.text.w) * env->data.text.opp) + 2];
		((unsigned int *)env->img_data)[calc->x +
		(calc->line_begin * LEN)] = ret_colors(calc->color1);
		calc->line_begin++;
	}
}

void						draw_wall(t_env *env, t_calc *calc)
{
	while (calc->line_begin < calc->line_end)
	{
		if (env->data.color_option == 0 || env->data.color_option == 3)
			((unsigned int *)env->img_data)[calc->x +
				(calc->line_begin * LEN)] = color_determinator2(calc);
		else
		{
			calc->map_texty = calc->line_begin * 2 + calc->line_height - HEIGHT;
			calc->tex_y = ((calc->map_texty * env->data.text.h)
				/ calc->line_height) / 2;
			set_final_color(env, calc);
		}
		calc->line_begin++;
	}
}
