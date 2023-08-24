/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:19:17 by minjinki          #+#    #+#             */
/*   Updated: 2023/08/24 12:41:34 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	cal_dda(t_game *game)
{
	while (game->xpm.hit == 0)
	{
		if (game->xpm.sidedist_x < game->xpm.sidedist_y)
		{
			game->xpm.sidedist_x += game->xpm.deltadist_y;
			game->xpm.map_x += game->xpm.step_x;
			game->xpm.side = 0;
		}
		else
		{
			game->xpm.sidedist_y += game->xpm.deltadist_x;
			game->xpm.map_y += game->xpm.step_y;
			game->xpm.side = 1;
		}
		if (game->map.map[game->xpm.map_x][game->xpm.map_y] == '1')
			game->xpm.hit = 1;
	}
}

void	screen(t_game *game)
{
	if (game->xpm.side == 0)
		game->xpm.perpwalldist = (game->xpm.map_x - game->xpm.pos_x
				+ (1 - game->xpm.step_x) / 2) / game->xpm.raydir_x;
	else
		game->xpm.perpwalldist = (game->xpm.map_y - game->xpm.pos_y
				+ (1 - game->xpm.step_y) / 2) / game->xpm.raydir_y;
	game->xpm.height = (int)(HEIGHT / game->xpm.perpwalldist);
	game->xpm.start = -game->xpm.height / 2 + HEIGHT / 2;
	if (game->xpm.start < 0)
		game->xpm.start = 0;
	game->xpm.end = game->xpm.height / 2 + HEIGHT / 2;
	if (game->xpm.end >= HEIGHT)
		game->xpm.end = HEIGHT - 1;
}
