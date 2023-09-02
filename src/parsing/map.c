/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:40:59 by minjinki          #+#    #+#             */
/*   Updated: 2023/09/02 12:41:25 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	find_map(char *full_file, t_map *info)
{
	char	**check;
	int		number;
	int		size;

	check = ft_split(full_file, '\n');
	size = -1;
	while (check[++size])
		;
	number = 0;
	size -= 5;
	return (find_map_setting(info, check, size));
}

// 원본 배열을 복사하여 새로운 2차원 배열 생성
char	**copy_array(char **src, int rows, int cols)
{
	int		i;
	int		j;
	char	**dest;

	dest = (char **)malloc(rows * sizeof(char *) + 1);
	i = -1;
	while (++i < rows)
	{
		dest[i] = (char *)malloc(cols * sizeof(char) + 1);
		j = -1;
		while (++j < cols)
			dest[i][j] = src[i][j];
		dest[i][cols] = '\0';
	}
	dest[rows] = NULL;
	return (dest);
}

void	remake_map(t_map *map)
{
	int		i;
	int		j;
	int		ori_len;
	char	**newmap;

	i = -1;
	newmap = (char **)malloc(sizeof(char *) * map->height + 1);
	while (++i < map->height)
	{
		newmap[i] = (char *)malloc(sizeof(char *) * map->width + 1);
		j = -1;
		while (++j < map->width)
		{
			ori_len = ft_strlen(map->map[i]);
			newmap[i][j] = '3';
			if (ft_strchr("01NEWS", map->map[i][j]))
				newmap[i][j] = map->map[i][j];
			if (j >= ori_len)
				newmap[i][j] = '3';
		}
		newmap[i][j] = '\0';
	}
	newmap[map->height] = NULL;
	map->map_cp2 = copy_array(newmap, map->height, map->width);
	free_2d_array(newmap);
}

int	check_map(t_map *info)
{
	int	i;

	i = -1;
	while (++i < info->map_len)
	{
		if (i == 0 || i == info->map_len - 1)
		{
			if (check_row(info->map[i]))
				return (ft_error("Map isn't surrounded by wall\n"));
		}
		else
		{
			if (check_row2(info->map[i]))
				return (ft_error("Map isn't surrounded by wall\n"));
		}
	}
	if (check_row3(info))
		return (ft_error("Map isn't surrounded by wall\n"));
	return (0);
}

int	parsing_map(t_map *info, char *full_path)
{
	int	i;
	int	width;
	int	start_index;

	start_index = find_map(full_path, info);
	if (start_index == -1)
		return (ft_error("There are not enough arguments for the map.\n"));
	i = 0;
	width = 0;
	info->height = info->map_len;
	while (i < info->height)
	{
		width = ft_strlen(info->map[i]);
		if (width > info->width)
			info->width = width;
		i++;
	}
	if (check_spawn(info) != 1)
		return (ft_error("Wrong number of player\n"));
	if (check_map(info))
		return (1);
	return (0);
}
