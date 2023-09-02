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
// 맵 전체
// 캐릭터
// 텍스쳐

int	parsing_color(char *full_file, unsigned int *color, char *pattern)
{
	char	*line;
	char	**split;
	t_color	color_s;

	ft_bzero(&color_s, sizeof(t_color));
	line = create_line(full_file, pattern);
	if (!line)
		return (ft_error("\nRGB isn't found in Map\n"));
	split = ft_split(line, ',');
	if (check_rgb(split, &color_s))
	{
		free_2d_array(split);
		free(line);
		return (ft_error("\nRGB: ERROR\n"));
	}
	free_2d_array(split);
	free(line);
	*color = make_rgb(color_s.r, color_s.g, color_s.b);
	return (0);
}

int	parsing_texture(t_map *map, t_img *img)
{
	char	*tmp[4];

	tmp[0] = create_line(map->full_path, "NO ");
	tmp[1] = create_line(map->full_path, "EA ");
	tmp[2] = create_line(map->full_path, "WE ");
	tmp[3] = create_line(map->full_path, "SO ");
	img->north = remove_spaces(tmp[0]);
	img->east = remove_spaces(tmp[1]);
	img->west = remove_spaces(tmp[2]);
	img->south = remove_spaces(tmp[3]);
	free(tmp[0]);
	free(tmp[1]);
	free(tmp[2]);
	free(tmp[3]);
	if (!(img->north) || !(img->west)
		|| !(img->south) || !(img->east))
		return (ft_error("path is wrong\n"));
	return (0);
}

int check_can_Go(char *check)
{
	if (check[0] == ' ')
		return (1);
	else if (!ft_strchr(check, 'F') && !ft_strchr(check, 'C'))
		return (0);
	return (0);
}

int	find_map_setting4(t_map *info, char **check)
{
	int size;
	int flag;
	int start = 0;
	int	i[3];
	int height = 0;

	i[0] = -1;
	i[1] = 0;
	size = 0;
	flag = 1;
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
				start = i[0];
			}
		}
	}
	info->map_cp3 = (char **)ft_calloc(size + 1, sizeof(char *));
	while (start < i[0])
		info->map_cp3[height++] = ft_strdup(check[start++]);
	free_2d_array(check);
	return (height);
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

int	check_four_forward2(t_map *info, int y, int x)
{
	if (y < 0 || x < 0 || y == info->height || x == info->width)
		return (1);
	if (info->map_cp4[y + 1][x] == '3' || info->map_cp4[y][x + 1] == '3'
		|| info->map_cp4[y - 1][x] == '3' || info->map_cp4[y][x - 1] == '3'
		|| info->map_cp4[y][x] == '3')
		return (1);
	info->map_cp4[y][x] = '1';
	if (info->map_cp4[y - 1][x] == '0')
		return (check_four_forward2(info, y - 1, x));
	if (info->map_cp4[y + 1][x] == '0')
		return (check_four_forward2(info, y + 1, x));
	if (info->map_cp4[y][x + 1] == '0')
		return (check_four_forward2(info, y, x + 1));
	if (info->map_cp4[y][x - 1] == '0')
		return (check_four_forward2(info, y, x - 1));
	return (0);
}

int ft_strange_map_check(t_map *info, char *map)
{
	char **map2d;
	int height;
	int width;
	int i = -1;
	int j;


	map2d = ft_split(map, '\n');
	height = find_map_setting4(info, map2d);
	remake_map2(info, height);

	i = -1;
	// while (info->map_cp4[++i])
	// 	printf("%s\n", info->map_cp4[i]);
	while (++i < height)
	{
		printf("%s", info->map_cp4[i]);
		j = -1;
		width = ft_strlen(info->map_cp4[i]);
		while (++j < width)
		{
			if (info->map_cp4[i][j] == '0')
				if (check_four_forward2(info, i, j))
					ft_error("Map is not blocked\n");
		}
	}
	free_2d_array(info->map_cp3);
	free_2d_array(info->map_cp4);
	return (0);
}

int	parsing_all(int fd, t_game *game_all, t_map *map_all)
{
	int	ret;

	ret = check_buff_end(fd, &(map_all->full_path), &(map_all->full_path_space));

	if (ret == -1)
		return (ft_error(""));
	if (parsing_color(map_all->full_path, &map_all->floor_color, "F ")
		|| parsing_color(map_all->full_path, &map_all->cell_color, "C ")
		|| parsing_map(map_all, map_all->full_path)
		|| ft_strange_map_check(map_all, map_all->full_path_space)
		|| parsing_texture(map_all, &game_all->img))
	{
		return (1);
	}
	free(map_all->full_path_space);
	return (0);
}

// 들어오는 입력에 대해서 구조체에 초기화 하는 함수
int	init_input(t_game *game_all, char *map_path)
{
	int	fd;

	fd = open(map_path, O_RDONLY);
	if (fd == -1)
		return (ft_error("Map isn't exist\n"));
	printf("-------------------------------\n\t Map is opened\n");
	printf("-------------------------------\n");
	if (parsing_all(fd, game_all, &game_all->map))
		return (1);
	close(fd);
	printf("-------------------------------\n\t Map is closed\n");
	printf("-------------------------------\n");
	return (0);
}

// 파씽 전부다 마무리하는 함수
int	ft_parsing_master(char **argv, t_game *game_all)
{
	int	count;

	if (init_input(game_all, argv[1]))
		return (1);
	free(game_all->map.full_path);
	count = 0;
	if (game_all->map.map)
	{
		while (count < game_all->map.map_len)
		{
			free(game_all->map.map_cp[count]);
			free(game_all->map.map_cp2[count]);
			count++;
		}
		free(game_all->map.map_cp);
		free(game_all->map.map_cp2);
	}
	printf("\n");
	return (0);
}
