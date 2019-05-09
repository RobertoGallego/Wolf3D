/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3_normalize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ocojeda- <ocojeda-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 09:24:06 by ocojeda-          #+#    #+#             */
/*   Updated: 2019/01/20 09:24:20 by ocojeda-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmat4.h"

t_vec3	vec3_normalize(t_vec3 v)
{
	float	magnitude;

	magnitude = vec3_magnitude(v);
	v.v[0] /= magnitude;
	v.v[1] /= magnitude;
	v.v[2] /= magnitude;
	return (v);
}
