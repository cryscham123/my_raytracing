/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:38:32 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/31 16:56:30 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

t_lst	*mk_lst(void *data, int data_type, int info)
{
	t_lst	*target;

	target = ft_calloc(sizeof(t_lst));
	target->data = data;
	target->data_type = data_type;
	target->info = info;
	return (target);
}

void	lst_push(t_lst **target, t_lst *to_push)
{
	t_lst	*tmp;

	tmp = *target;
	if (tmp == NULL)
	{
		*target = to_push;
		(*target)->size = 1;
		return ;
	}
	while (tmp->nxt != NULL)
		tmp = tmp->nxt;
	tmp->nxt = to_push;
	if (to_push != NULL)
		to_push->prev = tmp;
	(*target)->size++;
}
