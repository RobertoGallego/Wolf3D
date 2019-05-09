/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groberto <groberto@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/27 14:25:42 by groberto          #+#    #+#             */
/*   Updated: 2019/04/30 16:21:25 by groberto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_color				copy_color(t_color color)
{
	t_color		newcolor;

	newcolor.r = color.r;
	newcolor.g = color.g;
	newcolor.b = color.b;
	return (newcolor);
}

t_color				color_mult(t_color color, float taux, float limit)
{
	t_color		new_color;

	new_color = copy_color(color);
	new_color.r = (color.r == 0 && taux > limit) ? 1 * taux : color.r * taux;
	new_color.g = (color.g == 0 && taux > limit) ? 1 * taux : color.g * taux;
	new_color.b = (color.b == 0 && taux > limit) ? 1 * taux : color.b * taux;
	new_color.r = (new_color.r > 255) ? 255 : new_color.r;
	new_color.g = (new_color.g > 255) ? 255 : new_color.g;
	new_color.b = (new_color.b > 255) ? 255 : new_color.b;
	new_color.r = (new_color.r < 0) ? 0 : new_color.r;
	new_color.g = (new_color.g < 0) ? 0 : new_color.g;
	new_color.b = (new_color.b < 0) ? 0 : new_color.b;
	return (new_color);
}

t_color				ft_map_color(t_color color1, t_color color2, float taux1)
{
	t_color		new_color;
	float		taux2;

	if (taux1 >= 1)
		return (color2);
	taux2 = 1 - taux1;
	color1 = color_mult(color1, taux2, 1);
	color2 = color_mult(color2, taux1, 1);
	new_color.r = color1.r + color2.r;
	new_color.g = color1.g + color2.g;
	new_color.b = color1.b + color2.b;
	return (new_color);
}

unsigned int		color_determinator(t_calc *calc)
{
	t_color color_tmp;

	color_tmp = copy_color(calc->color1);
	if (calc->side == 1)
	{
		color_tmp.r = 150;
		color_tmp.b = 0;
		color_tmp.g = 0;
		calc->color1 = ft_map_color(calc->color1, color_tmp, 0.5);
		if (calc->ray.v[0] > 0)
		{
			color_tmp.b = 150;
			calc->color1 = ft_map_color(calc->color1, color_tmp, 0.5);
		}
	}
	else
	{
		color_tmp.g = 150;
		calc->color1 = ft_map_color(calc->color1, color_tmp, 0.5);
		if (calc->ray.v[1] > 0)
		{
			calc->color1 = copy_color(color_tmp);
		}
	}
	return (ret_colors(calc->color1));
}

unsigned int		color_determinator2(t_calc *calc)
{
	unsigned int	color;

	color = 0x9F81F7;
	if (calc->side == 1)
	{
		color = color / 2;
		if (calc->ray.v[0] > 0)
			color /= 4;
	}
	else
	{
		color = color / 6;
		if (calc->ray.v[1] > 0)
			color /= 8;
	}
	return (color);
}
