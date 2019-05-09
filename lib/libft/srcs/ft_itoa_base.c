/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 11:29:23 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/06/28 11:29:26 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count(int value, int base)
{
	if (value > base - 1)
	{
		return (ft_count(value / base, base) + 1);
		return (ft_count(value % base, base) + 1);
	}
	else
		return (1);
}

void	ft_convert(int value, int base, char *str)
{
	char	c;
	int		i;

	i = 0;
	if (value > base - 1)
	{
		ft_convert(value / base, base, str);
		ft_convert(value % base, base, str);
	}
	else
	{
		c = value + '0';
		if (value > 9)
			c = c + 7;
		while (str[i] != 0)
			i++;
		str[i] = c;
	}
}

char	*create_malloc(int count)
{
	int		i;
	char	*ret;

	i = -1;
	ret = (char *)malloc(count + 1);
	while (++i <= count + 1)
		ret[i] = '\0';
	return (ret);
}

char	*ft_itoa_base(int value, int base)
{
	char	*ret;
	int		count;
	int		negative;

	if (!(base > 1 && base < 17))
		return (0);
	negative = 0;
	count = 0;
	if (value < 0)
	{
		negative = 1;
		value = value * -1;
	}
	count = ft_count(value, base);
	if (negative == 1 && base == 10)
		count++;
	ret = create_malloc(count);
	if (ret)
	{
		if (negative == 1 && base == 10)
			ret[0] = '-';
		ft_convert(value, base, ret);
	}
	return (ret);
}
