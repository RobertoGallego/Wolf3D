/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_calc_find_the_wall.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <groberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 16:35:16 by ocojeda-          #+#    #+#             */
/*   Updated: 2019/04/30 16:21:39 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void						find_the_first_wall_hit(t_env *env, t_calc *calc)
{
	int						hit;

	hit = 0;
	while (hit == 0)
	{
		if (calc->distance.v[1] < calc->distance.v[0])
		{
			calc->distance.v[1] += calc->delta.v[1];
			calc->mapper_x += calc->step_x;
			calc->side = 0;
		}
		else
		{
			calc->distance.v[0] += calc->delta.v[0];
			calc->mapper_y += calc->step_y;
			calc->side = 1;
		}
		if (env->data.map[calc->mapper_x][calc->mapper_y] == '1')
			hit = 1;
	}
}

void						distance_to_cam(t_env *env, t_calc *calc)
{
	if (calc->ray.v[1] < 0)
	{
		calc->step_x = -1;
		calc->distance.v[1] = (env->data.player_pos.v[1] -
			calc->mapper_x) * calc->delta.v[1];
	}
	else
	{
		calc->step_x = 1;
		calc->distance.v[1] = (calc->mapper_x + 1.0 -
			env->data.player_pos.v[1]) * calc->delta.v[1];
	}
	if (calc->ray.v[0] < 0)
	{
		calc->step_y = -1;
		calc->distance.v[0] = (env->data.player_pos.v[0] -
		calc->mapper_y) * calc->delta.v[0];
	}
	else
	{
		calc->step_y = 1;
		calc->distance.v[0] = (calc->mapper_y + 1.0 -
			env->data.player_pos.v[0]) * calc->delta.v[0];
	}
}

void						init_calc_data(t_env *env, t_calc *calc)
{
	calc->cam_overx = 2 * calc->x / (float)(LEN) - 1;
	calc->ray = vec3_add(env->data.cam_dir,
		vec3_fmul(env->data.plane, calc->cam_overx));
	calc->mapper_x = env->data.player_pos.v[1];
	calc->mapper_y = env->data.player_pos.v[0];
	calc->delta = vec3(fabs(1 / calc->ray.v[0]), fabs(1 / calc->ray.v[1]), 0);
	distance_to_cam(env, calc);
	find_the_first_wall_hit(env, calc);
}

void						set_base_calcs(t_env *env, t_calc *calc)
{
	init_calc_data(env, calc);
	calc_distance_to_wall(env, calc);
	calc_line(calc);
	map_texture(env, calc);
}
