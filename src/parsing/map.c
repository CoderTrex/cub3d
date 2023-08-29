/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 14:40:59 by minjinki          #+#    #+#             */
/*   Updated: 2023/08/29 15:00:18 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	find_map(char *full_file, t_map *info)
{
	char	**check;
	int		number;
	int		i;
	int		j;
	int		size;
	int		total;

	check = ft_split(full_file, '\n');
	total = -1;
	while (check[++total])
		;
	i = -1;
	number = 0;
	size = total - 5;
	while (check[++i])
	{
		if (ft_strstr(check[i], "NO") || ft_strstr(check[i], "EA")
			|| ft_strstr(check[i], "SO") || ft_strstr(check[i], "WE")
			|| ft_strstr(check[i], "F ") || ft_strstr(check[i], "C "))
				number++;
		if (number == 6 && (ft_strchr(check[i], '1') && !ft_strchr(check[i], 'F') && !ft_strchr(check[i], 'C')))
		{
			info->map = (char **)malloc(sizeof(char *) * size + 1);
			info->map_cp = (char **)malloc(sizeof(char *) * size + 1);
			j = 0;
			while (size - 1 > j)
			{
				info->map[j] = ft_strdup(check[i]);
				info->map_cp[j] = ft_strdup(check[i++]);
				j++;
			}
			info->map[j] = NULL;
			info->map_cp[j] = NULL;
			info->map_len = j;
			free_2d_array(check);
			return (i);
		}
	}
	free_2d_array(check);
	return (-1);
}

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
				if (map->map[i][j] == 'N' || map->map[i][j] == 'W'
				|| map->map[i][j] == 'E' || map->map[i][j] == 'S')
				{
					map->py = j;
					map->pos = map->map[i][j];
				}
			}
		}
	}
	if (character == 1)
		return (0);
	return (1);
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
			{
				printf("%s\n", str);
				return (1);
			}
			break ;
		}
		i++;
	}
	if (str[len - 1] != '1')
	{
		printf("%s\n", str);
		return (1);
	}
	return (0);
}

int	check_four_forward(t_map *info, int y, int x)
{
	if (y < 0 || x < 0 || y == info->height || x == info->width)
	{
		printf("test: ERROR four forward %c\n", info->map_cp2[y][x]);
		return (1);
	}
	if (info->map_cp2[y + 1][x] == '3' || info->map_cp2[y][x + 1] == '3'
		|| info->map_cp2[y - 1][x] == '3' || info->map_cp2[y][x - 1] == '3'
		|| info->map_cp2[y][x] == '3')
	{
		printf("test: ERROR four forward %c, and position: %d, %d\n",
			info->map_cp2[y][x], x, y);
		return (1);
	}
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

// 원본 배열을 복사하여 새로운 2차원 배열 생성
char**	copy_array(char** src, int rows, int cols) 
{
	int		i;
	int		j;
	char**	dest;

	dest = (char**)malloc(rows * sizeof(char *) + 1);
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
	int		width_ori_len;
	char	**newmap;

	i = -1;
	newmap = (char **)malloc(sizeof(char *) * map->height + 1);
	while (++i < map->height)
	{
		newmap[i] = (char *)malloc(sizeof(char *) * map->width + 1);
		j = -1;
		width_ori_len = ft_strlen(map->map[i]);
		while (++j < map->width)
		{
			if (j >= width_ori_len)
				newmap[i][j] = '3';
			else if (map->map[i][j] == '0' || map->map[i][j] == '1'
				|| map->map[i][j] == 'N' || map->map[i][j] == 'S'
				|| map->map[i][j] == 'W' || map->map[i][j] == 'E')
					newmap[i][j] = map->map[i][j];
			else
				newmap[i][j] = '3';
		}
		newmap[i][j] = '\0';
	}
	newmap[map->height] = NULL;
	map->map_cp2 = copy_array(newmap, map->height, map->width);
	free_2d_array(newmap);
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
	while (++i < height)
	{
		j = -1;
		width = ft_strlen(map->map[i]);
		while (++j < width)
		{
			if (map->map[i][j] == '0')
				check_four_forward(map, i, j);
		}
	}
	return (0);
}
// 조건
// 1. 사방이 전부 1로 둘러싸여야한다.
// 2번 조건 다른 게 있을까? 없는 것 같은디...
// 주변이 1로 둘러쌓여 잇으면 되는 건데 그 왜 조건 있나?

int	check_map(t_map *info)
{
	int i;

	i = -1;
	while (++i < info->map_len)
	{
		if (i == 0 || i == info->map_len - 1)
		{
			if (check_row(info->map[i]))
			{
				printf("%s\n", info->map[i]);
				return (1);
			}
		}
		else
		{
			if (check_row2(info->map[i]))
			{
				ft_error("ERROR: map isn't surrounded wall\n");
				return (1);
			}
		}
	}
	if (check_row3(info))
	{
		ft_error("ERROR: map isn't surrounded wall\n");
		return (1);
	}
	return (0);
}

int	parsing_map(t_map *info, char *full_path)
{
	int	i;
	int	width;
	int	start_index;

	start_index = find_map(full_path, info);
	if (start_index == -1)
		return (ft_error("Invalid map area"));
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
	if (check_spawn(info))
		return (ft_error("NSWE is not in the map\n"));
	if (check_map(info))
		return (ft_error("Map is not surrounded wall\n"));
	return (0);
}
