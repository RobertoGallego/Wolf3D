/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 10:55:37 by ocojeda-          #+#    #+#             */
/*   Updated: 2019/05/03 12:40:27 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		mouse_hook_escape(t_env *env)
{
	if (env)
		exit(0);
	return (1);
}

t_vec3	move_if_not_wall(t_env *env, t_vec3 pos)
{
	if (pos.v[1] <= 1)
		pos.v[1] = 1.00001;
	if (pos.v[0] <= 1)
		pos.v[0] = 1.00001;
	if (pos.v[1] >= (float)(env->data.ms - 1))
		pos.v[1] = (float)(env->data.ms - 1.00001);
	if (pos.v[0] >= (float)(env->data.ms - 1))
		pos.v[0] = (float)(env->data.ms - 1.00001);
	if (env->data.map[(int)pos.v[1]][(int)pos.v[0]] == '1')
		return (env->data.player_pos);
	return (pos);
}

void	key_code_movements(int keycode, t_env *env)
{
	if (keycode == 123)
	{
		env->data.cam_rot.v[0] += 0.00001;
		env->data.cam_dir = vec3_rotate2(&env->data.cam_dir, env->data.cam_rot);
		env->data.plane = vec3_rotate2(&env->data.plane, env->data.cam_rot);
	}
	if (keycode == 124)
	{
		env->data.cam_rot.v[0] -= 0.00001;
		env->data.cam_dir = vec3_rotate2(&env->data.cam_dir,
		vec3_fmul(env->data.cam_rot, -1));
		env->data.plane = vec3_rotate2(&env->data.plane,
		vec3_fmul(env->data.cam_rot, -1));
	}
	if (keycode == 126)
		env->data.player_pos = move_if_not_wall(env,
			vec3_sub(env->data.player_pos,
			vec3_fmul(env->data.cam_dir, env->data.cam_rot.v[0])));
	if (keycode == 125)
		env->data.player_pos = move_if_not_wall(env,
			vec3_add(env->data.player_pos,
			vec3_fmul(env->data.cam_dir, env->data.cam_rot.v[0])));
}

int		my_key_func(int keycode, t_env *env)
{
	key_code_movements(keycode, env);
	if (keycode == 53)
		exit(0);
	if (keycode == 83)
		env->data.color_option = 0;
	if (keycode == 84)
		env->data.color_option = 1;
	if (keycode == 85)
		env->data.color_option = 2;
	if (keycode == 86)
		env->data.color_option = 3;
	find_the_wall(env);
	put_mlx(env);
	return (1);
}
