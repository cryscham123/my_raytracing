/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 09:41:45 by hyunghki          #+#    #+#             */
/*   Updated: 2023/08/09 14:49:04 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculate_bonus.h"
#include "vector_bonus.h"

t_color	ft_calculate(t_ray *ray, t_info *info)
{
	t_rec	rec;
	double	t;

	rec.min = 0.001;
	rec.max = INFINITY;
	if (is_hit(ray, info->objs, &rec))
		return (phong_light(ray, &rec, info));
	t = 0.5 * (ray->dir.y + 1.0);
	return (vec_plus(\
			vec_multi(initial_vec(1.0, 1.0, 1.0), (1.0 - t)), \
			vec_multi(initial_vec(0.5, 0.7, 1.0), t)));
}
