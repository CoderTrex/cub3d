/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 14:44:48 by minjinki          #+#    #+#             */
/*   Updated: 2023/07/19 14:45:59 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	dfs(t_map *map, char **visited, int x, int y)
{
	if (map->map[x][y] == '1' || visited[x][y] == 1)
		return ;
	if (x < 0 || y < 0 || x >= map->height || y >= map->width)
		exit_with_code(1, "Map is not closed\n");
	visited[x][y] = 1;
	dfs(map, visited, x + 1, y);
	dfs(map, visited, x - 1, y);
	dfs(map, visited, x, y + 1);
	dfs(map, visited, x, y - 1);
}
