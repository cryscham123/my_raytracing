/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mk_struct2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 09:09:19 by hyunghki          #+#    #+#             */
/*   Updated: 2023/08/09 19:12:56 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"
#include "utils_bonus.h"

static t_sphere	*mk_sp(t_lst *target)
{
	t_sphere	*ret;

	ret = ft_calloc(sizeof(t_sphere));
	ft_get_coord(&ret->coord, target->data);
	target = target->nxt;
	ret->radius = ft_atod(target->data);
	if (ret->radius < 0)
		ft_error();
	ret->radius /= 2;
	target = target->nxt;
	ft_get_obj_rgb(&ret->rgb, &ret->checker_rgb, target->data);
	target = target->nxt;
	if (target != NULL)
		ret->img = get_bump(target->data);
	return (ret);
}

static t_plane	*mk_pl(t_lst *target)
{
	t_plane	*ret;

	ret = ft_calloc(sizeof(t_plane));
	ft_get_coord(&ret->coord, target->data);
	target = target->nxt;
	ft_get_axis(&ret->axis, target->data);
	target = target->nxt;
	ft_get_obj_rgb(&ret->rgb, &ret->checker_rgb, target->data);
	target = target->nxt;
	if (target != NULL)
		ret->img = get_bump(target->data);
	return (ret);
}

static t_cy_cn	*mk_cy_cn(t_lst *target)
{
	t_cy_cn	*ret;

	ret = ft_calloc(sizeof(t_cylinder));
	ft_get_coord(&ret->coord, target->data);
	target = target->nxt;
	ft_get_axis(&ret->axis, target->data);
	target = target->nxt;
	ret->radius = ft_atod(target->data);
	if (ret->radius < 0)
		ft_error();
	ret->radius /= 2.0;
	target = target->nxt;
	ret->height = ft_atod(target->data);
	if (ret->height < 0)
		ft_error();
	target = target->nxt;
	ft_get_obj_rgb(&ret->rgb, &ret->checker_rgb, target->data);
	target = target->nxt;
	if (target != NULL)
		ret->img = get_bump(target->data);
	return (ret);
}

void	ft_parse_objs(t_lst **objs, t_lst *target)
{
	t_lst	*to_push;

	to_push = NULL;
	if (ft_strcmp(target->data, "sp") == 0 && target->size == 4)
		to_push = mk_lst(mk_sp(target->nxt), F_DATA_OBJS, F_SP);
	else if (ft_strcmp(target->data, "pl") == 0 && target->size == 4)
		to_push = mk_lst(mk_pl(target->nxt), F_DATA_OBJS, F_PL);
	else if (ft_strcmp(target->data, "cy") == 0 && target->size == 6)
		to_push = mk_lst(mk_cy_cn(target->nxt), F_DATA_OBJS, F_CY);
	else if (ft_strcmp(target->data, "cn") == 0 && target->size == 6)
		to_push = mk_lst(mk_cy_cn(target->nxt), F_DATA_OBJS, F_CN);
	else if (ft_strcmp(target->data, "sp") == 0 && target->size == 5)
		to_push = mk_lst(mk_sp(target->nxt), F_DATA_OBJS, F_SP + F_BUMP);
	else if (ft_strcmp(target->data, "pl") == 0 && target->size == 5)
		to_push = mk_lst(mk_pl(target->nxt), F_DATA_OBJS, F_PL + F_BUMP);
	else if (ft_strcmp(target->data, "cy") == 0 && target->size == 7)
		to_push = mk_lst(mk_cy_cn(target->nxt), F_DATA_OBJS, F_CY + F_BUMP);
	else if (ft_strcmp(target->data, "cn") == 0 && target->size == 7)
		to_push = mk_lst(mk_cy_cn(target->nxt), F_DATA_OBJS, F_CN + F_BUMP);
	else
		ft_error();
	lst_push(objs, to_push);
}
