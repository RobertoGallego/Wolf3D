/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_wall_final_adder.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 18:21:01 by ocojeda-          #+#    #+#             */
/*   Updated: 2019/05/01 18:29:43 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	map_copy_translate(t_env *env, char **map2)
{
	int i;
	int x;

	i = 0;
	while (i < env->data.ms)
	{
		x = 0;
		while (x < env->data.ms)
		{
			map2[i + 1][x + 1] = env->data.map[i][x];
			x++;
		}
		i++;
	}
	free_splited_str(env->data.map);
	env->data.map = map2;
	env->data.ms += 2;
	env->data.map_height += 2;
	env->data.player_pos.v[1] += 1;
	env->data.player_pos.v[0] += 1;
}

void	bigger_map_alloc(t_env *env, char **map2)
{
	int x;
	int i;

	i = 1;
	while (i < env->data.ms + 2)
	{
		x = 0;
		map2[i] = (char *)ft_memalloc(sizeof(char) * (env->data.ms + 3));
		if (!map2[i])
			ft_error("alloc error");
		while (x < env->data.ms + 2)
		{
			ft_memset(map2[i], '1', env->data.ms + 2);
			x++;
		}
		i++;
	}
}

void	fix_final_map(t_env *env)
{
	char **map2;

	map2 = (char **)ft_memalloc(sizeof(char *) * (env->data.ms + 2));
	if (!map2)
		ft_error("malloc not working");
	map2[0] = (char *)ft_memalloc(sizeof(char) * (env->data.ms + 3));
	if (!map2[0])
		ft_error("malloc not working");
	ft_memset(map2[0], '1', env->data.ms + 2);
	bigger_map_alloc(env, map2);
	map_copy_translate(env, map2);
	if (env->data.player == 0)
		put_player_position(env->data.map[3], &env->data);
}
