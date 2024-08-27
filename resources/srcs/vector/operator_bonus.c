/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operator_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:29:13 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/30 15:27:16 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_bonus.h"

t_vec3	initial_vec(double x, double y, double z)
{
	t_vec3	target;

	target.x = x;
	target.y = y;
	target.z = z;
	return (target);
}

t_vec3	vec_plus(t_vec3 v1, const t_vec3 v2)
{
	v1.x += v2.x;
	v1.y += v2.y;
	v1.z += v2.z;
	return (v1);
}

t_vec3	vec_minus(t_vec3 v1, t_vec3 v2)
{
	v1.x -= v2.x;
	v1.y -= v2.y;
	v1.z -= v2.z;
	return (v1);
}

t_vec3	vec_devide(t_vec3 v, double to_devide)
{
	v.x /= to_devide;
	v.y /= to_devide;
	v.z /= to_devide;
	return (v);
}

t_vec3	vec_multi(t_vec3 v, double to_multi)
{
	v.x *= to_multi;
	v.y *= to_multi;
	v.z *= to_multi;
	return (v);
}
