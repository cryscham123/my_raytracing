/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_type_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 07:35:44 by hyunghki          #+#    #+#             */
/*   Updated: 2023/08/11 18:40:57 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_TYPE_BONUS_H
# define DATA_TYPE_BONUS_H

# include <pthread.h>

# define F_DATA_CHAR 1
# define F_DATA_LST 2
# define F_DATA_OBJS 3
# define F_LIGHTS 1
# define F_SP 2
# define F_PL 4
# define F_CY 8
# define F_CN 16
# define F_BUMP 64

typedef struct s_lst
{
	void			*data;
	int				data_type;
	int				info;
	int				size;
	struct s_lst	*nxt;
	struct s_lst	*prev;
}	t_lst;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef t_vec3	t_color;

typedef struct s_ray
{
	t_vec3	origin;
	t_vec3	dir;
}	t_ray;

typedef struct s_amb
{
	t_color	min_rgb;
	t_color	rgb;
}	t_amb;

typedef struct s_cam
{
	t_vec3	coord;
	t_vec3	axis;
	double	fov;
}	t_cam;

typedef struct s_light
{
	t_vec3	coord;
	double	ratio;
	t_color	rgb;
}	t_light;

typedef struct s_bump
{
	void			*img_addr;
	void			*access_addr;
	int				bpp;
	int				line_length;
	int				endian;
	char			*file_name;
	unsigned int	**val;
	int				width;
	int				height;
}	t_bump;

typedef struct s_sphere
{
	t_vec3	coord;
	double	radius;
	t_color	rgb;
	t_color	checker_rgb;
	t_bump	*img;
}	t_sphere;

typedef struct s_plane
{
	t_vec3	coord;
	t_vec3	axis;
	t_color	rgb;
	t_color	checker_rgb;
	t_bump	*img;
}	t_plane;

typedef struct s_cy_cn
{
	t_vec3	coord;
	t_vec3	axis;
	double	radius;
	double	height;
	t_color	rgb;
	t_color	checker_rgb;
	t_bump	*img;
}	t_cy_cn;

typedef t_cy_cn	t_cylinder;
typedef t_cy_cn	t_cone;

typedef struct s_info
{
	t_cam	*cam;
	t_amb	*amb;
	t_lst	*lights;
	t_lst	*objs;
	t_vec3	origin;
	t_vec3	u_dir;
	t_vec3	v_dir;
	t_vec3	low_left;
}	t_info;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
	int				is_error;
	pthread_mutex_t	start;
	pthread_mutex_t	put_img;
	t_info			*info;
}		t_data;

typedef struct s_thr
{
	int			st_col;
	int			en_col;
	pthread_t	thr;
	t_data		*data;
}	t_thr;

#endif
