/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interface_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:29:15 by hyunghki          #+#    #+#             */
/*   Updated: 2023/08/11 15:43:38 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render_bonus.h"
#include "utils_bonus.h"
#include "vector_bonus.h"

static void	ft_initial_info(t_info *info, t_cam *cam, t_amb *amb, t_lst *lights)
{
	double	focal_len;

	if (vec_length(vec_cross(cam->axis, initial_vec(0, 1, 0))))
		info->u_dir = vec_unit(vec_cross(cam->axis, initial_vec(0, 1, 0)));
	else if (cam->axis.y < 0)
		info->u_dir = vec_unit(vec_cross(cam->axis, initial_vec(0, 0, -1)));
	else
		info->u_dir = vec_unit(vec_cross(cam->axis, initial_vec(0, 0, 1)));
	info->v_dir = vec_unit(vec_cross(info->u_dir, cam->axis));
	info->origin = cam->coord;
	focal_len = (double)WIDTH / 2.0 / tan(cam->fov / 2.0 * M_PI / 180.0);
	info->low_left = vec_minus(\
			vec_plus(info->origin, vec_multi(cam->axis, focal_len)), \
			vec_plus(\
			vec_multi(info->u_dir, (double)(WIDTH - 1) / 2), \
			vec_multi(info->v_dir, (double)(HEIGHT - 1) / 2)));
	info->cam = cam;
	info->amb = amb;
	info->lights = lights;
}

static int	ft_handle_mouse(int keycode, int x, int y, t_data *data)
{
	t_vec3	look_at;
	t_info	*info;

	info = data->info;
	if (keycode == K_SCROLL_CLICK)
	{
		look_at = info->low_left;
		look_at = vec_plus(look_at, vec_multi(info->u_dir, x));
		look_at = vec_plus(look_at, vec_multi(info->v_dir, HEIGHT - 1 - y));
		info->cam->axis = vec_unit(vec_minus(look_at, info->origin));
	}
	else if (keycode == K_SCROLL_UP)
		info->cam->coord.y += 3.0;
	else if (keycode == K_SCROLL_DOWN)
		info->cam->coord.y -= 3.0;
	else
		return (0);
	ft_initial_info(info, info->cam, info->amb, info->lights);
	print_img(data);
	return (0);
}

static int	ft_handle_key(int keycode, t_data *data)
{
	t_info	*info;
	t_cam	*cam;

	info = data->info;
	cam = info->cam;
	if (keycode == K_ESC)
		exit(EXIT_SUCCESS);
	else if (keycode == K_A)
		cam->coord = vec_minus(cam->coord, vec_multi(info->u_dir, 3));
	else if (keycode == K_W)
		cam->coord = vec_plus(cam->coord, vec_multi(cam->axis, 3));
	else if (keycode == K_D)
		cam->coord = vec_plus(cam->coord, vec_multi(info->u_dir, 3));
	else if (keycode == K_S)
		cam->coord = vec_minus(cam->coord, vec_multi(cam->axis, 3));
	else
		return (0);
	ft_initial_info(info, info->cam, info->amb, info->lights);
	print_img(data);
	return (0);
}

static int	ft_close(int keycode)
{
	(void)keycode;
	exit(EXIT_SUCCESS);
	return (0);
}

void	ft_render(t_amb *amb, t_cam *cam, t_lst *lights, t_lst *objs)
{
	t_data	data;
	t_info	info;

	data.mlx = mlx_init();
	if (data.mlx == NULL)
		ft_error();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "miniRT");
	if (data.win == NULL)
		ft_error();
	data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
	if (data.img == NULL)
		ft_error();
	data.addr = mlx_get_data_addr(data.img, &data.bpp, \
			&data.line_length, &data.endian);
	ft_initial_info(&info, cam, amb, lights);
	ft_get_bump_info(&data, objs);
	info.objs = objs;
	data.info = &info;
	ft_create_mutex(&data);
	print_img(&data);
	mlx_key_hook(data.win, ft_handle_key, &data);
	mlx_mouse_hook(data.win, ft_handle_mouse, &data);
	mlx_hook(data.win, 17, 1L, ft_close, NULL);
	mlx_loop(data.mlx);
}
