/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:40:59 by minjinki          #+#    #+#             */
/*   Updated: 2023/08/29 16:13:24 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	find_map_setting2(char *check)
{
	if (ft_strstr(check, "NO") || ft_strstr(check, "EA")
		|| ft_strstr(check, "SO") || ft_strstr(check, "WE")
		|| ft_strstr(check, "F ") || ft_strstr(check, "C "))
		return (1);
	else
		return (0);
}

int	find_map_setting3(char *check, int i)
{
	if (i == 6 && (ft_strchr(check, '1')
			&& !ft_strchr(check, 'F') && !ft_strchr(check, 'C')))
		return (1);
	else
		return (0);
}

int	find_map_setting(t_map *info, char **check, int size)
{
	int	i[3];

	i[1] = 0;
	i[0] = -1;
	while (check[++i[0]])
	{
		if (find_map_setting2(check[i[0]]))
			i[1]++;
		if (find_map_setting3(check[i[0]], i[1]))
		{
			info->map = (char **)ft_calloc(size + 1, sizeof(char *));
			info->map_cp = (char **)ft_calloc(size + 1, sizeof(char *));
			i[2] = 0;
			while (size - 1 > i[2])
			{
				info->map[i[2]] = ft_strdup(check[i[0]]);
				info->map_cp[i[2]++] = ft_strdup(check[i[0]++]);
			}
			info->map_len = i[2];
			free_2d_array(check);
			return (i[0]);
		}
	}
	free_2d_array(check);
	return (-1);
}
