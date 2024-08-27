/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_cal2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:02:52 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/30 15:27:10 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_bonus.h"

t_vec3	ray_at(t_ray *ray, double t)
{
	return (vec_plus(ray->origin, vec_multi(ray->dir, t)));
}

t_vec3	vec_unit(t_vec3 v)
{
	double	len;

	len = vec_length(v);
	v.x /= len;
	v.y /= len;
	v.z /= len;
	return (v);
}
