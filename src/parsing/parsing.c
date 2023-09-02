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

int	parsing_all(int fd, t_game *game_all, t_map *map_all)
{
	int	ret;

	ret = check_buff_end(fd, &(map_all->full_path),
			&(map_all->full_path_space));
	if (ret == -1)
		return (ft_error("ERROR"));
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
