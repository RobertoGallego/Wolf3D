/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <groberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/22 11:22:30 by ocojeda-          #+#    #+#             */
/*   Updated: 2019/04/30 16:33:48 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	get_image(t_texture *texture, char *buffer, int i)
{
	int	h;
	int	j;
	int	size;

	h = 0;
	size = texture->size * 2;
	texture->img = (unsigned char*)ft_memalloc(sizeof(unsigned char) * size);
	if (texture->img == NULL)
		ft_error("malloc failure");
	while (i >= 0)
	{
		i -= texture->sl;
		j = 0;
		while (j < texture->sl)
		{
			texture->img[h + j] = (unsigned char)buffer[i + j + 2];
			texture->img[h + j + 1] = (unsigned char)buffer[i + j + 1];
			texture->img[h + j + 2] = (unsigned char)buffer[i + j];
			j += 3;
		}
		h += texture->sl;
	}
}

void	read_header(char *filename, t_texture *texture)
{
	FILE	*file;

	if ((file = fopen(filename, "r")) == NULL)
		ft_error("BMP reader fail =(");
	fseek(file, 18, SEEK_SET);
	fread(&texture->w, 4, 1, file);
	fread(&texture->h, 4, 1, file);
	fseek(file, 2, SEEK_CUR);
	fread(&texture->bpp, 2, 1, file);
	fclose(file);
	texture->opp = texture->bpp / 8;
	texture->sl = texture->w * texture->opp;
	texture->w < 0 ? texture->w = -texture->w : 0;
	texture->h < 0 ? texture->h = -texture->h : 0;
	texture->size = texture->sl * texture->h;
}

void	load_bmp(t_env *env, char *filename)
{
	int		fd;
	int		i;
	char	*buffer;

	read_header(filename, &env->data.text);
	if (!(buffer = (char*)ft_memalloc(sizeof(char) * env->data.text.size + 1)))
		ft_error("malloc failure");
	if ((fd = open(filename, O_RDWR)) == -1)
		ft_error("bmp file opening failed.");
	lseek(fd, 54, SEEK_SET);
	i = read(fd, buffer, env->data.text.size);
	get_image(&env->data.text, buffer, i);
	ft_strdel((char**)&buffer);
	close(fd);
}
