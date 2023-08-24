/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 16:19:17 by minjinki          #+#    #+#             */
/*   Updated: 2023/08/24 13:44:18 by minjinki         ###   ########.fr       */
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

void	get_hit_pos(t_game *game)
{
	if (game->xpm.side == 0)
		game->xpm.perpwalldist = (game->xpm.map_x - game->xpm.pos_x
				+ (1 - game->xpm.step_x) / 2) / game->xpm.raydir_x;
	else
		game->xpm.perpwalldist = (game->xpm.map_y - game->xpm.pos_y
				+ (1 - game->xpm.step_y) / 2) / game->xpm.raydir_y;
	game->xpm.height = (int)(HEIGHT / game->xpm.perpwalldist);
	game->xpm.start = HEIGHT / 2 - game->xpm.height / 2;
	if (game->xpm.start < 0)
		game->xpm.start = 0;
	game->xpm.end = game->xpm.height / 2 + HEIGHT / 2;
	if (game->xpm.end >= HEIGHT)
		game->xpm.end = HEIGHT - 1;
}

void	set_texture(t_game *game, void *texture)
{
	if (game->xpm.side == 0)
	{
		if (game->xpm.raydir_x < 0)
			add_tex = mlx_get_data_addr(game->mlx, )
			
	}
}

void	draw_texture(t_game *game, int i, int map_y, void *texture)
{
	int	y;
	int	color;

	y = game->xpm.start;
	while (y <= game->xpm.end)
	{
		game->xpm.tex_y = (int)game->xpm.tex_pos & (IMG_H - 1);
		game->xpm.tex_pos += game->xpm.step;
		color = ((int *)texture)[IMG_H * game->xpm.tex_y + game->xpm.tex_x];
		game->buf[y][i] = color;
		y++;
	}
}
