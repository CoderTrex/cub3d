/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjinki <minjinki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 17:52:58 by minjinki          #+#    #+#             */
/*   Updated: 2023/08/31 12:11:45 by minjinki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	paint_floor_ceiling(t_game *game)
{
	int	x;
	int	y;
	int	mid;

	y = 0;
	mid = HEIGHT / 2;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			if (y < mid)
				put_pixel(game, x, y, game->map.cell_color);
			else
				put_pixel(game, x, y, game->map.floor_color);
			x++;
		}
		y++;
	}
}

void	set_side_dist(t_xpm *xpm)
{
	if (xpm->raydir_x < 0)
	{
		xpm->step_x = -1;
		xpm->sidedist_x = (xpm->pos_x - xpm->map_x) * xpm->deltadist_x;
	}
	else
	{
		xpm->step_x = 1;
		xpm->sidedist_x = (xpm->map_x + 1.0 - xpm->pos_x) * xpm->deltadist_x;
	}
	if (xpm->raydir_y < 0)
	{
		xpm->step_y = -1;
		xpm->sidedist_y = (xpm->pos_y - xpm->map_y) * xpm->deltadist_y;
	}
	else
	{
		xpm->step_y = 1;
		xpm->sidedist_y = (xpm->map_y + 1.0 - xpm->pos_y) * xpm->deltadist_y;
	}
}

void	init_ray(t_game *game, int i)
{
	game->xpm.camera_x = 2 * i / (double)WIDTH - 1;
	game->xpm.raydir_x
		= game->xpm.dir_x + game->xpm.plane_x * game->xpm.camera_x;
	game->xpm.raydir_y
		= game->xpm.dir_y + game->xpm.plane_y * game->xpm.camera_x;
	game->xpm.map_x = (int)game->xpm.pos_x;
	game->xpm.map_y = (int)game->xpm.pos_y;
	game->xpm.deltadist_x = fabs(1 / game->xpm.raydir_x);
	game->xpm.deltadist_y = fabs(1 / game->xpm.raydir_y);
	game->xpm.hit = 0;
	set_side_dist(&(game->xpm));
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

void	render_img(t_game *game)
{
	int	i;

	paint_floor_ceiling(game);
	i = -1;
	while (++i < WIDTH)
	{
		init_ray(game, i);
		cal_dda(game);
		get_hit_pos(game);
		draw_texture(game, i);
	}
	print_map_with_player(game);
}
