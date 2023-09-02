/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 15:09:47 by minjinki          #+#    #+#             */
/*   Updated: 2023/08/29 15:56:38 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_spawn(t_map *map)
{
	int	i;
	int	j;
	int	character;

	i = -1;
	j = -1;
	character = 0;
	while (map->map_len > ++i)
	{
		if (ft_strchr(map->map[i], 'N') || ft_strchr(map->map[i], 'W')
			|| ft_strchr(map->map[i], 'E') || ft_strchr(map->map[i], 'S'))
		{
			character++;
			map->px = i;
			while (map->map[i][++j])
			{
				if (ft_strchr("NEWS", map->map[i][j]))
				{
					map->py = j;
					map->pos = map->map[i][j];
				}
			}
		}
	}
	return (character);
}

int	check_row(char *str)
{
	int	i;
	int	len;

	i = -1;
	len = ft_strlen(str);
	while (++i < len)
	{
		if (str[i] != ' ' && str[i] != '1')
			return (1);
	}
	return (0);
}

int	check_row2(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		if (str[i] != ' ')
		{
			if (str[i] != '1')
				return (1);
			break ;
		}
		i++;
	}
	if (str[len - 1] != '1')
		return (1);
	return (0);
}

int	check_four_forward(t_map *info, int y, int x)
{
	if (y < 0 || x < 0 || y == info->height || x == info->width)
		return (1);
	if (info->map_cp2[y + 1][x] == '3' || info->map_cp2[y][x + 1] == '3'
		|| info->map_cp2[y - 1][x] == '3' || info->map_cp2[y][x - 1] == '3'
		|| info->map_cp2[y][x] == '3')
		return (1);
	info->map_cp2[y][x] = '1';
	if (info->map_cp2[y - 1][x] == '0')
		return (check_four_forward(info, y - 1, x));
	if (info->map_cp2[y + 1][x] == '0')
		return (check_four_forward(info, y + 1, x));
	if (info->map_cp2[y][x + 1] == '0')
		return (check_four_forward(info, y, x + 1));
	if (info->map_cp2[y][x - 1] == '0')
		return (check_four_forward(info, y, x - 1));
	return (0);
}

int	check_row3(t_map *map)
{
	int	i;
	int	j;
	int	height;
	int	width;

	remake_map(map);
	i = -1;
	height = map->height;
	i = -1;
	while (++i < height)
	{
		j = -1;
		width = ft_strlen(map->map[i]);
		while (++j < width)
		{
			if (map->map[i][j] == '0')
				if (check_four_forward(map, i, j))
					ft_error("Map is not blocked\n");
			if (i == (int)map->px && j == (int)map->py)
				if (check_four_forward(map, i, j))
					ft_error("Map is not blocked\n");
		}
	}
	return (0);
}
