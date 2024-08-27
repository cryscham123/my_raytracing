/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmory_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:38:28 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/31 12:04:02 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

static void	*ft_node_free(void *data, int data_type)
{
	if (data == NULL)
		return (NULL);
	if (data_type == F_DATA_LST)
		return (ft_lst_free(data));
	free(data);
	return (NULL);
}

void	*ft_lst_free(t_lst *target)
{
	t_lst	*tmp;

	while (target != NULL)
	{
		ft_node_free(target->data, target->data_type);
		tmp = target;
		target = target->nxt;
		free(tmp);
	}
	return (NULL);
}

void	*ft_calloc(int size)
{
	int				i;
	unsigned char	*target;

	target = malloc(size);
	if (target == NULL)
		ft_error();
	i = 0;
	while (i < size)
	{
		target[i] = 0;
		i++;
	}
	return (target);
}

void	ft_create_mutex(t_data *data)
{
	if (pthread_mutex_init(&data->start, NULL) != 0)
		ft_error();
	if (pthread_mutex_init(&data->put_img, NULL) != 0)
		ft_error();
}

void	ft_join(int n, t_thr *thr)
{
	int	i;

	i = -1;
	while (++i < n)
		pthread_join(thr[i].thr, NULL);
}
