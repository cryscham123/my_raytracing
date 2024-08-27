/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 09:32:29 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/30 15:25:52 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_BONUS_H
# define VECTOR_BONUS_H

# include "data_type_bonus.h"
# include "math.h"

t_vec3	initial_vec(double x, double y, double z);
t_vec3	vec_plus(t_vec3 v1, const t_vec3 v2);
t_vec3	vec_minus(t_vec3 v1, t_vec3 v2);
t_vec3	vec_devide(t_vec3 v, double to_devide);
t_vec3	vec_multi(t_vec3 v, double to_multi);
t_vec3	vec_cross(t_vec3 v1, t_vec3 v2);
double	vec_length_squared(t_vec3 v);
double	vec_length(t_vec3 v);
double	vec_dot(t_vec3 v1, t_vec3 v2);
t_vec3	vec_cross(t_vec3 v1, t_vec3 v2);
t_vec3	vec_reflect(t_vec3 v1, t_vec3 v2);
t_vec3	vec_multi_vec(t_vec3 v1, t_vec3 v2);
t_vec3	vec_min(t_vec3 v1, t_vec3 v2);
t_vec3	vec_max(t_vec3 v1, t_vec3 v2);
t_vec3	vec_unit(t_vec3 v);
t_vec3	ray_at(t_ray *ray, double t);

#endif
