/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:52:59 by minjinki          #+#    #+#             */
/*   Updated: 2023/09/02 12:44:26 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_strange_map_check(t_map *info, char *map)
{
	char	**map2d;
	int		height;
	int		width;
	int		i;
	int		j;

	i = -1;
	map2d = ft_split(map, '\n');
	height = find_map_setting4(info, map2d);
	remake_map2(info, height);
	while (++i < height)
	{
		printf("%s\n", info->map_cp4[i]);
		j = -1;
		width = ft_strlen(info->map_cp4[i]);
		while (++j < width)
		{
			if (info->map_cp4[i][j] == '0')
				if (check_four_forward2(info, i, j, height))
					ft_error("Map is not blocked\n");
		}
	}
	free_2d_array(info->map_cp3);
	free_2d_array(info->map_cp4);
	return (0);
}

int	make_map3(t_map *info, char **check, int size, int i)
{
	int	height;

	height = 0;
	info->map_cp3 = (char **)ft_calloc(size + 1, sizeof(char *));
	while (info->start < i)
		info->map_cp3[height++] = ft_strdup(check[info->start++]);
	free_2d_array(check);
	return (height);
}

int	find_map_setting4(t_map *info, char **check)
{
	int	size;
	int	flag;
	int	start;
	int	i[3];

	i[0] = -1;
	i[1] = 0;
	size = 0;
	flag = 1;
	start = 0;
	while (check[++i[0]])
	{	
		if (find_map_setting2(check[i[0]], i[1]) == 1)
			i[1]++;
		if (i[1] == 6 && check[i[0]][0] != 'F' && check[i[0]][0] != 'C')
		{
			size++;
			if (flag == 1)
			{
				flag = 0;
				info->start = i[0];
			}
		}
	}
	return (make_map3(info, check, size, i[0]));
}

void	remake_map2(t_map *map, int height)
{
	int		i;
	int		j;
	int		ori_len;
	char	**newmap;

	i = -1;
	newmap = (char **)malloc(sizeof(char *) * height + 1);
	while (++i < height)
	{
		newmap[i] = (char *)malloc(sizeof(char *) * map->width + 1);
		j = -1;
		while (++j < map->width)
		{
			ori_len = ft_strlen(map->map_cp3[i]);
			newmap[i][j] = '3';
			if (ft_strchr("01NEWS", map->map_cp3[i][j]))
				newmap[i][j] = map->map_cp3[i][j];
			if (j >= ori_len)
				newmap[i][j] = '3';
		}
		newmap[i][j] = '\0';
	}
	newmap[height] = NULL;
	map->map_cp4 = copy_array(newmap, height, map->width);
	free_2d_array(newmap);
}

int	check_four_forward2(t_map *info, int y, int x, int h)
{
	if (y < 0 || x < 0 || y == h || x == info->width)
	{
		printf("hellos\n");
		return (1);
	}
	if (info->map_cp4[y + 1][x] == '3' || info->map_cp4[y][x + 1] == '3'
		|| info->map_cp4[y - 1][x] == '3' || info->map_cp4[y][x - 1] == '3'
		|| info->map_cp4[y][x] == '3')
	{
		printf("hello1\n");
		return (1);
	}
	info->map_cp4[y][x] = '1';
	if (info->map_cp4[y - 1][x] == '0')
		return (check_four_forward2(info, y - 1, x, h));
	if (info->map_cp4[y + 1][x] == '0')
		return (check_four_forward2(info, y + 1, x, h));
	if (info->map_cp4[y][x + 1] == '0')
		return (check_four_forward2(info, y, x + 1, h));
	if (info->map_cp4[y][x - 1] == '0')
		return (check_four_forward2(info, y, x - 1, h));
	return (0);
}
