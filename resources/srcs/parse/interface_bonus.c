/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:12:25 by hyunghki          #+#    #+#             */
/*   Updated: 2023/08/09 16:28:21 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"
#include "get_next_line_bonus.h"
#include "utils_bonus.h"

static t_lst	*ft_mk_node(char *s)
{
	t_lst	*data;
	t_lst	*ret;

	if (*s == '\0')
		return (NULL);
	ret = NULL;
	data = ft_split_lst(s);
	ret = mk_lst(data, F_DATA_LST, 0);
	return (ret);
}

static t_lst	*get_data(char *file_name)
{
	t_lst	*ret;
	t_lst	*to_push;
	char	*line;
	int		fd;

	ret = NULL;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		ft_error();
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		to_push = ft_mk_node(ft_trim(line));
		if (to_push != NULL)
			lst_push(&ret, to_push);
		free(line);
	}
	close(fd);
	return (ret);
}

t_lst	*ft_parse(char *file_name, t_amb **amb, t_cam **cam, t_lst **lights)
{
	char	*data;
	t_lst	*target;
	t_lst	*tmp;
	t_lst	*objs;

	target = get_data(file_name);
	if (target == NULL)
		ft_error();
	objs = NULL;
	tmp = target;
	while (target != NULL)
	{
		data = ((t_lst *)target->data)->data;
		if (*data >= 'A' && *data <= 'Z')
			ft_parse_acl(amb, cam, lights, target->data);
		else
			ft_parse_objs(&objs, target->data);
		target = target->nxt;
	}
	ft_lst_free(tmp);
	if (*amb == NULL || *cam == NULL || *lights == NULL)
		ft_error();
	return (objs);
}
