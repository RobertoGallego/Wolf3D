/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 10:57:02 by ocojeda-          #+#    #+#             */
/*   Updated: 2019/05/01 18:28:37 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			wolf_line_checker2(char *str, t_data *data, int i)
{
	if (!str)
		return (1);
	while (str[i] && data->final_border == 1 && data->border_map == 1)
	{
		if (str[i] == '5')
		{
			data->player_pos.v[1] = 3;
			data->player_pos.v[0] = i + 0.5;
			data->player = 1;
		}
		if (str[i] == '0' || str[i] == '5')
			str[i] = '1';
		i++;
	}
	if (data->player >= 2)
		ft_error("Too many players (5), pick just one position.");
	return (0);
}

void		get_map(int fd, t_data *data, int i, int x)
{
	char	*line;
	char	*temp;

	while ((x = get_next_line(fd, &line)))
	{
		if (i < 0)
			ft_error("gnl error");
		if ((int)ft_strlen(line) == data->ms)
		{
			if (line[0] == '0' || line[0] == '5')
				line[0] = '1';
			if (line[data->ms - 1] == '0'
			|| line[data->ms - 1] == '5')
				line[data->ms - 1] = '1';
			data->map[i] = ft_strdup(line);
			if (wolf_line_checker(data->map[i], data))
				ft_error("only 0 1 or 5 accepted inside the map");
			temp = NULL;
			check_player_pos(data, i++, temp);
			free(line);
		}
		else
			ft_error("map error, lines are uneven");
	}
	get_map2(data, i);
}

void		get_map2(t_data *data, int i)
{
	char	*temp;

	if (data->ms != i)
		ft_error("U must have a square map. ex: 5x5");
	i--;
	data->final_border = 1;
	wolf_line_checker(data->map[i], data);
	temp = NULL;
	check_player_pos(data, i++, temp);
	data->map_height = i;
	if (data->ms != data->map_height)
		ft_error("U must have a square map");
	data->map[i] = NULL;
	if (data->ms < 4 || i < 4)
		ft_error("Your map is too small, try another one!. ex: 5x5");
}

void		check_player_pos(t_data *data, int i, char *temp)
{
	if (data->p_exists != 1)
	{
		if ((temp = ft_strchr(data->map[i], '5')))
		{
			data->player_pos.v[0] = temp - data->map[i];
			data->player_pos.v[1] = i;
			data->player_pos.v[0] += 0.3;
			data->player_pos.v[1] += 0.3;
			data->p_exists = 1;
		}
	}
}

int			parse(t_env *env, char *filename)
{
	int		fd;
	int		i;
	char	*line;
	char	*temp;

	i = 0;
	env->data.player = 0;
	if (check_file(filename))
		ft_error("Only .wolf file");
	if ((fd = open(filename, O_RDONLY)) == -1)
		ft_error("Unable to read the file");
	if (get_next_line(fd, &line) <= 0)
		ft_error("get_next_line error");
	env->data.ms = ft_strlen(line);
	env->data.map = (char **)ft_memalloc(sizeof(char *) * (env->data.ms + 1));
	if (env->data.map == NULL)
		ft_error("malloc failure");
	env->data.map[i] = ft_strdup(line);
	if (wolf_line_checker(env->data.map[i], &env->data))
		ft_error("only 0 1 or 5 accepted inside the map");
	temp = NULL;
	check_player_pos(&env->data, i++, temp);
	free(line);
	get_map(fd, &env->data, i, 0);
	return (1);
}
