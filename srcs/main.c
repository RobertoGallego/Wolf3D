/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 10:55:46 by ocojeda-          #+#    #+#             */
/*   Updated: 2019/05/01 18:21:17 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		check_file(char *str)
{
	int i;

	i = ft_strlen(str);
	if (i > 5)
		if (ft_strcmp(&str[i - 5], ".wolf"))
			return (1);
	return (0);
}

int		wolf_line_checker(char *str, t_data *data)
{
	int	i;

	i = 0;
	if (!str)
		return (1);
	while (str[i] && data->border_map == 0)
	{
		if (str[i] == '0' || str[i] == '5')
			str[i] = '1';
		i++;
	}
	data->border_map = 1;
	i = 0;
	while (str[i] && data->border_map == 1 && data->final_border == 0)
	{
		if (str[i] == '0' || str[i] == '1' || str[i] == '5')
		{
			if (str[++i] == '5')
				data->player++;
		}
		else
			return (1);
	}
	wolf_line_checker2(str, data, 0);
	return (0);
}

int		put_player_position(char *str, t_data *data)
{
	int i;

	i = 0;
	if (!str)
		return (1);
	while (str[i] && data->player == 0)
	{
		if (str[i] == '0')
		{
			data->player_pos.v[1] = 3.5;
			data->player_pos.v[0] = i + 0.5;
			data->player = 1;
		}
		i++;
	}
	if (data->player == 0)
		ft_error("Change player position (5) we cant found one for u :(");
	return (0);
}

int		main(int ac, char **av)
{
	t_env	e;

	if (ac != 2)
		ft_error("wrong arg");
	e.data.border_map = 0;
	e.data.final_border = 0;
	parse(&e, av[1]);
	fix_final_map(&e);
	init_data(&e);
	init_mlx(&e);
	load_bmp(&e, "./duck_original.bmp");
	find_the_wall(&e);
	put_mlx(&e);
	mlx_hook(e.win, 2, 0, my_key_func, &e);
	mlx_hook(e.win, 17, 0, mouse_hook_escape, &e);
	mlx_loop(e.mlx);
	return (1);
}
