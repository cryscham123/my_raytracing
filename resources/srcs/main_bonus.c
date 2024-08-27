/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:06:36 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/30 15:26:22 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_bonus.h"
#include "render_bonus.h"
#include "utils_bonus.h"

static int	is_rt_file(char *file_name)
{
	int	n;

	n = ft_strlen(file_name);
	if (file_name[n - 3] != '.' \
		|| file_name[n - 2] != 'r' \
		|| file_name[n - 1] != 't')
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_amb	*amb;
	t_cam	*cam;
	t_lst	*lights;
	t_lst	*objs;

	if (argc != 2 || !is_rt_file(argv[1]))
		ft_error();
	amb = NULL;
	cam = NULL;
	lights = NULL;
	objs = ft_parse(argv[1], &amb, &cam, &lights);
	ft_render(amb, cam, lights, objs);
	free(amb);
	free(cam);
	ft_lst_free(lights);
	ft_lst_free(objs);
	return (0);
}
