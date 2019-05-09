/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 11:41:15 by ocojeda-          #+#    #+#             */
/*   Updated: 2017/06/28 11:43:06 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*memory;
	size_t	i;

	memory = (char *)malloc(size);
	if (!memory)
		return (NULL);
	i = 0;
	while (i < size)
	{
		memory[i] = 0;
		i++;
	}
	return (memory);
}
