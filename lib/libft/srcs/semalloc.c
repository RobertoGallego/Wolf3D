/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   semalloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 11:46:35 by ocojeda-          #+#    #+#             */
/*   Updated: 2019/01/20 15:13:36 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*semalloc(size_t size)
{
	void *new;

	if (!(new = malloc(size)))
		ft_error("malloc failed");
	return (new);
}
