/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <groberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 10:55:13 by ocojeda-          #+#    #+#             */
/*   Updated: 2019/04/30 16:21:43 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			init_data(t_env *env)
{
	env->data.cam_dir.v[0] = 0;
	env->data.cam_dir.v[1] = -1;
	env->data.plane = vec3(0.66, 0, 0);
	env->data.cam_rot = vec3(-0.1, 0, 0);
	env->data.color_option = 0;
}
