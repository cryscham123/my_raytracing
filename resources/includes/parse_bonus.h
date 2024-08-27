/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 06:48:31 by hyunghki          #+#    #+#             */
/*   Updated: 2023/08/09 16:34:24 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_BONUS_H
# define PARSE_BONUS_H

# include <fcntl.h>
# include <stdlib.h>
# include "data_type_bonus.h"

t_lst	*ft_parse(char *file_name, t_amb **amb, t_cam **cam, t_lst **lights);
void	ft_get_coord(t_vec3 *coord, char *s);
void	ft_get_axis(t_vec3 *axis, char *s);
void	ft_get_rgb(t_color *rgb, char *s);
void	ft_get_obj_rgb(t_color *rgb, t_color *checker_rgb, char *s);
void	ft_parse_acl(t_amb **amb, t_cam **cam, t_lst **lights, t_lst *target);
void	ft_parse_objs(t_lst **objs, t_lst *target);
t_bump	*get_bump(char *s);

#endif
