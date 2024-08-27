/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 09:59:53 by hyunghki          #+#    #+#             */
/*   Updated: 2023/08/09 19:26:59 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"
#include "render_bonus.h"
#include "vector_bonus.h"
#include "calculate_bonus.h"

static unsigned int	get_color(t_color rgb)
{
	int	r;
	int	g;
	int	b;

	r = rgb.x * 255;
	g = rgb.y * 255;
	b = rgb.z * 255;
	return ((r << 16) + (g << 8) + b);
}

static void	ft_put_pixel(t_data *data, int x, int y, unsigned int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

static void	print_img_exe(t_data *data, t_info *info, int st_col, int en_col)
{
	t_ray	ray;
	int		y;
	int		x;

	y = -1;
	while (++y < HEIGHT)
	{
		x = st_col - 1;
		while (++x < en_col)
		{
			ray.origin = info->origin;
			ray.dir = info->low_left;
			ray.dir = vec_plus(ray.dir, vec_multi(info->u_dir, x));
			ray.dir = vec_plus(ray.dir, vec_multi(info->v_dir, HEIGHT - 1 - y));
			ray.dir = vec_minus(ray.dir, info->origin);
			ray.dir = vec_unit(ray.dir);
			ft_put_pixel(data, x, y, get_color(ft_calculate(&ray, info)));
		}
	}
	pthread_mutex_lock(&data->put_img);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	pthread_mutex_unlock(&data->put_img);
}

static void	*print_img_help(void *arg)
{
	t_thr		*thr;
	int			is_error;

	thr = arg;
	pthread_mutex_lock(&thr->data->start);
	is_error = thr->data->is_error;
	pthread_mutex_unlock(&thr->data->start);
	if (is_error != 0)
		return (NULL);
	print_img_exe(thr->data, thr->data->info, thr->st_col, thr->en_col);
	return (NULL);
}

void	print_img(t_data *data)
{
	t_thr		*thr;
	int			split_size;
	int			i;

	if (SCREEN == 0 || WIDTH % SCREEN != 0)
		ft_error();
	thr = ft_calloc(sizeof(t_thr) * SCREEN);
	mlx_clear_window(data->mlx, data->win);
	split_size = WIDTH / SCREEN;
	i = -1;
	pthread_mutex_lock(&data->start);
	while (++i < SCREEN)
	{
		thr[i].data = data;
		thr[i].st_col = i * split_size;
		thr[i].en_col = (i + 1) * split_size;
    data->is_error = (pthread_create(&thr[i].thr, NULL, \
                                     print_img_help, thr + i) != 0);
	}
	pthread_mutex_unlock(&data->start);
	ft_join(SCREEN, thr);
	if (data->is_error != 0)
		ft_error();
}
