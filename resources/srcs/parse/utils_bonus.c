/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 06:51:55 by hyunghki          #+#    #+#             */
/*   Updated: 2023/08/09 16:34:43 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector_bonus.h"
#include "parse_bonus.h"
#include "utils_bonus.h"

void	ft_get_coord(t_vec3 *coord, char *s)
{
	int	i;

	i = ft_str_find(s, ',');
	if (i == -1)
		ft_error();
	s[i] = '\0';
	coord->x = ft_atod(s);
	s += (i + 1);
	i = ft_str_find(s, ',');
	if (i == -1)
		ft_error();
	s[i] = '\0';
	coord->y = ft_atod(s);
	s += (i + 1);
	coord->z = ft_atod(s);
}

void	ft_get_axis(t_vec3 *axis, char *s)
{
	int	i;

	i = ft_str_find(s, ',');
	if (i == -1)
		ft_error();
	s[i] = '\0';
	axis->x = ft_atod(s);
	s += (i + 1);
	i = ft_str_find(s, ',');
	if (i == -1)
		ft_error();
	s[i] = '\0';
	axis->y = ft_atod(s);
	s += (i + 1);
	axis->z = ft_atod(s);
	if (vec_length_squared(*axis) != 1.0)
		ft_error();
}

void	ft_get_rgb(t_color *rgb, char *s)
{
	int	i;

	i = ft_str_find(s, ',');
	if (i == -1)
		ft_error();
	s[i] = '\0';
	rgb->x = ft_atod(s);
	if (rgb->x < 0 || rgb->x > 255)
		ft_error();
	s += (i + 1);
	i = ft_str_find(s, ',');
	if (i == -1)
		ft_error();
	s[i] = '\0';
	rgb->y = ft_atod(s);
	if (rgb->y < 0 || rgb->y > 255)
		ft_error();
	s += (i + 1);
	rgb->z = ft_atod(s);
	if (rgb->z < 0 || rgb->z > 255)
		ft_error();
	*rgb = vec_devide(*rgb, 255);
}

void	ft_get_obj_rgb(t_color *rgb, t_color *checker_rgb, char *s)
{
	int	i;

	i = ft_str_find(s, '|');
	if (i != -1)
		s[i] = '\0';
	ft_get_rgb(rgb, s);
	if (i != -1)
	{
		s += (i + 1);
		ft_get_rgb(checker_rgb, s);
	}
	else
		*checker_rgb = initial_vec(-1, -1, -1);
}

t_bump	*get_bump(char *s)
{
	t_bump	*target;
	int		i;
	int		n;

	target = ft_calloc(sizeof(t_bump));
	n = ft_strlen(s);
	target->file_name = ft_calloc(n + 1);
	i = 0;
	while (i < n)
	{
		target->file_name[i] = s[i];
		i++;
	}
	return (target);
}
