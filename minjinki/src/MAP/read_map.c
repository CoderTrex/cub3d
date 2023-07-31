/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 16:23:54 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/18 17:09:14 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	read_map(int fd, t_map *map)
{
	char	*s;
	char	*line;
	char	*tmp;

	line = ft_strdup("");
	s = get_next_line(fd);
	while (s)
	{
		if (ft_strlen(s) == 0)
			break ;
		tmp = ft_strjoin(line, s);
		if (!tmp)
			print_error("Fail to save map\n");
		free(line);
		free(s);
		line = tmp;
		s = get_next_line(fd);
	}
	if (ft_strlen(line) == 0)
		print_error("Empty map file\n");
	free(s);
	map->map = ft_split(line);
	if (!map->map)
		print_error("Fail to save map\n");
	free(line);
}
