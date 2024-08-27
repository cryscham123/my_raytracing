/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyunghki <hyunghki@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 10:21:49 by hyunghki          #+#    #+#             */
/*   Updated: 2023/07/30 15:28:48 by hyunghki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

int	ft_strnlen(const char *s, int maxlen)
{
	int	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (i < maxlen && s[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

char	*ft_trim(char *s)
{
	int	i;

	while (ft_str_find(" \n\t\v\f\r", *s) != -1)
		s++;
	i = ft_strlen(s) - 1;
	while (i >= 0 && ft_str_find(" \n\t\v\f\r", s[i]) != -1)
	{
		s[i] = '\0';
		i--;
	}
	return (s);
}

int	ft_str_find(char *s, char to_find)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == to_find)
			return (i);
		i++;
	}
	return (-1);
}
