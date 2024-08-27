/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_bump_info_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 16:07:24 by hyunghki          #+#    #+#             */
/*   Updated: 2023/08/14 18:40:36 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_bonus.h"
#include "utils_bonus.h"

static void	ft_get_bump_info_help(t_data *data, t_bump *img)
{
	unsigned int	*v;
	int				i;
	int				j;

	img->img_addr = mlx_xpm_file_to_image(data->mlx, img->file_name, \
		&img->width, &img->height);
	if (img->img_addr == NULL)
		ft_error();
	img->access_addr = mlx_get_data_addr(img->img_addr, &img->bpp, \
			&img->line_length, &img->endian);
	if (img->access_addr == NULL)
		ft_error();
	img->val = ft_calloc(sizeof(unsigned int *) * (img->width + 1));
	i = -1;
	while (++i < img->width)
	{
		j = -1;
		img->val[i] = ft_calloc(sizeof(unsigned int) * (img->height + 1));
		while (++j < img->height)
		{
			v = img->access_addr + (j * img->line_length + i * (img->bpp / 8));
			img->val[i][j] = *v;
		}
	}
}

void	ft_get_bump_info(t_data *data, t_lst *objs)
{
	t_bump	*img;

	while (objs)
	{
		if ((objs->info & F_BUMP) != 0)
		{
			if (objs->info & F_SP)
				img = ((t_sphere *)objs->data)->img;
			else if (objs->info & F_PL)
				img = ((t_plane *)objs->data)->img;
			else if ((objs->info & F_CY) || (objs->info & F_CN))
				img = ((t_cy_cn *)objs->data)->img;
			ft_get_bump_info_help(data, img);
		}
		objs = objs->nxt;
	}
}
