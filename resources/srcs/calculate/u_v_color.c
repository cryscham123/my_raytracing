/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_v_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 16:17:26 by hyunghki          #+#    #+#             */
/*   Updated: 2023/08/15 12:53:31 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "calculate_bonus.h"
#include "vector_bonus.h"
#include "utils_bonus.h"

static void	get_dir(t_rec *rec)
{
	if (vec_length(vec_cross(rec->normal, initial_vec(0, 1, 0))))
		rec->u_dir = vec_unit(vec_cross(rec->normal, initial_vec(0, 1, 0)));
	else if (rec->normal.y < 0)
		rec->u_dir = vec_unit(vec_cross(rec->normal, initial_vec(0, 0, -1)));
	else
		rec->u_dir = vec_unit(vec_cross(rec->normal, initial_vec(0, 0, 1)));
	rec->v_dir = vec_unit(vec_cross(rec->u_dir, rec->normal));
}

t_vec3	get_uv_color(t_rec *rec, t_color rgb, t_color checker_rgb, double size)
{
	int	val;

	val = floor(rec->u * size) + floor(rec->v * size);
	if ((val & 1) && checker_rgb.x >= 0)
		return (checker_rgb);
	return (rgb);
}

void	get_pl_uv(t_rec *rec, t_vec3 o, t_bump *img)
{
	double	w;
	double	h;
	t_vec3	target;

	get_dir(rec);
	w = 4.0;
	h = 4.0;
	if (img)
		h = w * (img->height / img->width);
	target = vec_minus(rec->p, o);
	rec->u = fmod(vec_dot(target, rec->u_dir), w);
	rec->v = fmod(vec_dot(target, rec->v_dir), h);
	rec->u = (w - fmod(rec->u, w)) / (2.0 * w);
	rec->v = (h - fmod(rec->v, h)) / (2.0 * h);
}

void	get_sp_uv(t_rec *rec, t_sphere *sp)
{
	t_vec3	target;
	double	theta;
	double	phi;

	get_dir(rec);
	target = vec_minus(rec->p, sp->coord);
	theta = atan2(target.z, target.x);
	phi = acos(target.y / sp->radius);
	rec->u = 1.0 - (theta / (2.0 * M_PI) + 0.5);
	rec->v = phi / M_PI;
}

void	get_c_uv(t_rec *rec, t_vec3 o, double v, t_cy_cn *c)
{
	int		cmp;
	double	theta;

	get_dir(rec);
	o = vec_minus(rec->p, vec_plus(o, vec_multi(c->axis, v)));
	cmp = ft_max(fabs(c->axis.x), fabs(c->axis.y), fabs(c->axis.z));
	if (cmp == 0 && c->axis.x > 0)
		theta = atan2(o.z, o.y);
	else if (cmp == 0 && c->axis.x < 0)
		theta = atan2(o.y, o.z);
	else if (cmp == 1 && c->axis.y > 0)
		theta = atan2(o.x, o.z);
	else if (cmp == 1 && c->axis.y < 0)
		theta = atan2(o.z, o.x);
	else if (cmp == 2 && c->axis.z > 0)
		theta = atan2(o.y, o.x);
	else
		theta = atan2(o.x, o.y);
	rec->u = 1.0 - (theta / (2.0 * M_PI) + 0.5);
	rec->v = v / c->height;
}
