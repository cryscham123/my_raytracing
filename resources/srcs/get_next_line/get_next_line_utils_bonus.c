/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/21 16:57:35 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/30 15:31:15 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include "utils_bonus.h"

static int	ft_gnl_set_buffer(char *buf, int st, int en)
{
	int	i;

	i = -1;
	while (++i + st < en)
		buf[i] = buf[i + st];
	buf[i] = '\0';
	return (1);
}

int	ft_gnl_strncat(char **s1, char *s2, int s1_size, int s2_size)
{
	char	*tmp;
	int		i;
	int		j;

	tmp = *s1;
	(*s1) = ft_calloc(s1_size + s2_size + 1);
	i = -1;
	while (++i < s1_size && tmp != NULL)
		(*s1)[i] = tmp[i];
	free(tmp);
	j = -1;
	while (++j < s2_size)
	{
		if (s2[j] == '\n')
			return (ft_gnl_set_buffer(s2, j + 1, s2_size));
		(*s1)[i + j] = s2[j];
	}
	return (0);
}
