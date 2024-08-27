/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mk_struct_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 08:59:05 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/30 15:39:49 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"
#include "utils_bonus.h"
#include "vector_bonus.h"

static t_amb	*mk_amb(t_lst *target)
{
	double	ratio;
	t_amb	*ret;

	ret = ft_calloc(sizeof(t_amb));
	ratio = ft_atod(target->data);
	if (ratio < 0.0 || ratio > 1.0)
		ft_error();
	target = target->nxt;
	ft_get_rgb(&ret->rgb, target->data);
	ret->rgb = vec_multi(ret->rgb, ratio);
	return (ret);
}

static t_cam	*mk_cam(t_lst *target)
{
	t_cam	*ret;

	ret = ft_calloc(sizeof(t_cam));
	ft_get_coord(&ret->coord, target->data);
	target = target->nxt;
	ft_get_axis(&ret->axis, target->data);
	target = target->nxt;
	ret->fov = ft_atod(target->data);
	if (ret->fov <= 0 || ret->fov >= 180)
		ft_error();
	return (ret);
}

static t_light	*mk_light(t_lst *target)
{
	t_light	*ret;

	ret = ft_calloc(sizeof(t_light));
	ft_get_coord(&ret->coord, target->data);
	target = target->nxt;
	ret->ratio = ft_atod(target->data);
	if (ret->ratio < 0.0 || ret->ratio > 1.0)
		ft_error();
	target = target->nxt;
	ft_get_rgb(&ret->rgb, target->data);
	return (ret);
}

void	ft_parse_acl(t_amb **amb, t_cam **cam, t_lst **lights, t_lst *target)
{
	if (ft_strcmp(target->data, "A") == 0 \
		&& target->size == 3 && *amb == NULL)
		*amb = mk_amb(target->nxt);
	else if (ft_strcmp(target->data, "C") == 0 \
		&& target->size == 4 && *cam == NULL)
		*cam = mk_cam(target->nxt);
	else if (ft_strcmp(target->data, "L") == 0 \
		&& target->size == 4)
		lst_push(lights, mk_lst(mk_light(target->nxt), F_DATA_OBJS, F_LIGHTS));
	else
		ft_error();
}
