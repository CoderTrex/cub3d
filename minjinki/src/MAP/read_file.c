/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:36:54 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/19 11:53:11 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	split_data(char *line, t_game *game)
{
	char	**data;

	data = ft_split(line, '\n');
	if (!data || !data[0])
		exit_with_code(1, "Fail to save data\n");
	if (ft_matrixlen(data) != 6)
		exit_with_code(1, "Check the number of map information\n");
	// check_data > 앞자리 문자가 NO, SO, WE, EA, F, C인지 확인
	// 공백은 전부 건너뛰어야 함
}

void	read_data(int fd, t_game *game)
{
	int		cnt;
	char	*s;
	char	*line;
	char	*tmp;

	line = ft_strdup("");
	s = get_next_line(fd);
	cnt = 0;
	while (s && cnt < 6)
	{
		if (ft_strlen(s) == 0)
			continue ;
		tmp = ft_strjoin(line, s);
		if (!tmp)
			print_error("Fail to save data\n");
		free(line);
		free(s);
		line = tmp;
		cnt++;
		s = get_next_line(fd);
	}
	split_data(line, game);
	free(s);
	free(line);
}

void	read_file(int fd, t_game *game)
{
	read_data(fd, game);
	read_map(fd, game->map);
}
