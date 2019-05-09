/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 11:26:14 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/06/28 11:26:16 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_ischar(char c, int power, unsigned int i, int base)
{
	if (ft_isalpha(c))
	{
		if ((c >= 65) && (c <= 90))
			i = i + ((c - 'A' + 10) * ft_pow(base, power));
		else
			i = i + ((c - 'a' + 10) * ft_pow(base, power));
	}
	else
		i = i + (c - '0') * ft_pow(base, power);
	return (i);
}

unsigned int	ft_atoi_base(char *nbr, int base)
{
	unsigned int	i;
	char			*str;
	char			str2[3];
	int				power;
	int				e;

	i = 0;
	if (!nbr)
		return (0);
	str = ft_strchr(nbr, 'x') + 1;
	power = ft_strlen(str) - 1;
	while (*str)
	{
		ft_strncpy(str2, str, 2);
		e = 0;
		while (str2[e])
		{
			i = ft_ischar(str2[e], power--, i, base);
			e++;
		}
		str += 2;
	}
	return (i);
}
