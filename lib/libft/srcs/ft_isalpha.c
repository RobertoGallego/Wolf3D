/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 11:27:12 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/06/28 11:27:27 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isalpha(int c)
{
	int	mincl;
	int maxcl;
	int	min;
	int max;

	min = 'a';
	max = 'z';
	mincl = 'A';
	maxcl = 'Z';
	if ((c >= min && c <= max) || (c >= mincl && c <= maxcl))
		return (1);
	else
		return (0);
}
