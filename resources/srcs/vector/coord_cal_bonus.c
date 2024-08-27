/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord_cal_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:30:44 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/30 15:27:04 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_bonus.h"

double	vec_length_squared(t_vec3 v)
{
	return (v.x * v.x + v.y * v.y + v.z * v.z);
}

double	vec_length(t_vec3 v)
{
	return (sqrt(vec_length_squared(v)));
}

double	vec_dot(t_vec3 v1, t_vec3 v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

t_vec3	vec_cross(t_vec3 v1, t_vec3 v2)
{
	t_vec3	target;

	target.x = v1.y * v2.z - v1.z * v2.y;
	target.y = v1.z * v2.x - v1.x * v2.z;
	target.z = v1.x * v2.y - v1.y * v2.x;
	return (target);
}

t_vec3	vec_reflect(t_vec3 v1, t_vec3 v2)
{
	return (vec_minus(v1, vec_multi(v2, vec_dot(v1, v2) * 2)));
}
