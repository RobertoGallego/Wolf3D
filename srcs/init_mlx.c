/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <groberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 10:55:26 by ocojeda-          #+#    #+#             */
/*   Updated: 2019/04/30 16:21:48 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		clear_img(t_env *env)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < (HEIGHT / 2))
	{
		x = 0;
		while (x < LEN)
		{
			((unsigned int *)env->img_data)[x + (y * LEN)] = 0x7EC0EE;
			x++;
		}
		y++;
	}
	while (y < HEIGHT)
	{
		x = 0;
		while (x < LEN)
		{
			((unsigned int *)env->img_data)[x + (y * LEN)] = 0xDEB887;
			x++;
		}
		y++;
	}
}

void		init_mlx(t_env *env)
{
	if (!(env->mlx = mlx_init()))
		ft_error("mlx failure");
	env->img = mlx_new_image(env->mlx, LEN, HEIGHT);
	env->img_data = mlx_get_data_addr(env->img, &env->bpp, &env->sizeline, \
	&env->endian);
	env->win = mlx_new_window(env->mlx, LEN, HEIGHT, "Wolf3d");
}

void		put_mlx(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
}
