/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 14:47:02 by hyunghki          #+#    #+#             */
/*   Updated: 2023/08/14 19:07:39 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_bonus.h"
#include "calculate_bonus.h"

static int	is_shadow(t_light *light, t_rec *rec, t_lst *objs)
{
	t_vec3	light_dir;
	t_ray	light_ray;
	double	light_len;
	t_rec	rec_tmp;

	light_dir = vec_minus(light->coord, rec->p);
	light_len = vec_length(light_dir);
	light_ray.origin = vec_plus(rec->p, vec_multi(rec->normal, 0.001));
	light_ray.dir = vec_unit(light_dir);
	rec_tmp.min = 0.001;
	rec_tmp.max = light_len;
	return (is_hit(&light_ray, objs, &rec_tmp));
}

static t_color	get_light(t_ray *ray, t_light *light, t_rec *rec, t_info *info)
{
	t_color	diffuse;
	t_color	specular;
	t_vec3	reflect_dir;
	t_vec3	view_dir;
	t_vec3	light_dir;

	if (is_shadow(light, rec, info->objs))
		return (initial_vec(0, 0, 0));
	light_dir = vec_unit(vec_minus(light->coord, rec->p));
	diffuse = vec_multi(light->rgb, fmax(vec_dot(light_dir, rec->normal), 0.0));
	reflect_dir = vec_reflect(vec_multi(light_dir, -1), rec->normal);
	view_dir = vec_unit(vec_multi(ray->dir, -1));
	specular = vec_multi(vec_multi(light->rgb, F_KS), \
			pow(fmax(vec_dot(reflect_dir, view_dir), 0.0), F_KSN));
	return (vec_multi(vec_plus(diffuse, specular), light->ratio));
}

t_color	phong_light(t_ray *ray, t_rec *rec, t_info *info)
{
	t_color	ret;
	t_lst	*lights;

	ret = info->amb->rgb;
	lights = info->lights;
	while (lights)
	{
		ret = vec_plus(ret, get_light(ray, lights->data, rec, info));
		lights = lights->nxt;
	}
	return (vec_min(vec_multi_vec(ret, rec->color), initial_vec(1, 1, 1)));
}
